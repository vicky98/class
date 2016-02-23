#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

struct node{
	char* data;
	struct node* next;
	struct node* prev;
};
struct node* head;
void write_stderr(char text[])
{
	write(STDERR_FILENO, text, strlen(text));
}

void write_stdout(char text[])
{
	if (write(STDOUT_FILENO, text, strlen(text)) != strlen(text)) {
		write(STDERR_FILENO, "There was an error writing to standard out\n", 44);
		return;
    }
}

void display_filename(char filename[])
{
	write_stdout("==> ");
	write_stdout(filename);
	write_stdout(" <==\n");
}

void display_err_wrr(char filename[], int status)
{
	if(status == 1)
	{
		return;
	}
	if(status == 0)
	{
		write_stderr("tail: cannot open ‘");
		write_stderr(filename);
		write_stderr("’ for reading: No such file or directory\n");
	}
	if(status == -1)
	{
		write_stderr("tail: cannot open ‘");
		write_stderr(filename);
		write_stderr("’ for reading: Permission denied\n");
	}
}

int empty()
{
	return head->next == head;
}
char* pop_back()
{
	if (empty()) 
	{
		return;
	}
	struct node* last = head->prev;
	struct node* new_last = last->prev;
	new_last->next = head;
	head->prev = new_last;
	char* result = last->data;
	free(last);
	return result;
}

void list_init()
{
	head = malloc(sizeof(struct node));
	head->next = head;
	head->prev = head;
}
void list_destroy()
{
	while(!empty())
	{
		pop_back();
	}
	free(head);
}
//----------------------
void push_back(char* value) 
{
	struct node* new_node = malloc(sizeof(struct node));
	new_node->data = value;
	struct node* last = head->prev;
	new_node->prev = last;
	new_node->next = head;
	last->next = new_node;
	head->prev = new_node;
}
//----------------------
char* pop_front()
{
	if (empty()) 
	{
		return;
	}
	struct node* first = head->next;
	struct node* new_first = first->next;
	head->next = new_first;
	new_first->prev = head;
	char* result = first->data;
	free(first);    
	return result;
}

//----------------------
int check_file(char filename[])
{
	if( access(filename, F_OK ) != -1 ) 
	{
		if(access(filename, R_OK)!= -1)
		{
			display_err_wrr(filename, 1);
			//we can read it
			return 1;
		}
		else
		{
			display_err_wrr(filename, -1);
			//we cant read it
			return -1;
		}
    // file exists
	} 
	else 
	{
		display_err_wrr(filename, 0);
    	// file doesn't exist
    	return 0;
	}
}
//----------------------
char *append(const char *s, char c)
{
    int len = strlen(s);
    char buf[len+2];
    strcpy(buf, s);
    buf[len] = c;
    buf[len + 1] = 0;
    return strdup(buf);
}

//----------------------
void read_input(int flag)
{
	if(flag)
	{
		write_stdout("==> ");
		write_stdout("standard input");
		write_stdout(" <==\n");;
	}
	list_init();
	char ch;
	char *line = "";
	int on_line = 0;
	while(read(STDIN_FILENO, &ch, 1) > 0)
	{
 		line = append(line, ch);
 		if(ch == '\n')
 		{
 			on_line++;
 			push_back(line);
 			if(on_line > 10)
 			{
 				pop_front();
 			}
 			line = "";
 		}
	}
	while(!empty())
	{
		write_stdout(pop_front());
 	}
	list_destroy();	
}

int lines_in_file(char filename[])
{
	int filedesc = open(filename, O_RDONLY);
	int n;
	char buf;
	int lines = 1;
	if(filedesc < 0)
	{
		check_file(filename);
		return;
	}
	while ((n=read(filedesc ,&buf,1))!=0)
	{
		if(buf == '\n')
		{
			lines++;
		}
	}
	close(filedesc);
	return lines;	
}

void read_file(char filename[], int flag)
{
	int filedesc = open(filename, O_RDONLY);
	if(filedesc < 0)
	{
		check_file(filename);
		return;
	}
	if(flag)
	{
		display_filename(filename);
	}
	int n;
	char buf;
	int lines = lines_in_file(filename);
	int from_line = 0;
	int curr_line = 1;
	from_line = lines - 10;
	while ((n=read(filedesc ,&buf,1))!=0)
	{
		if(buf == '\n')
		{
			curr_line++;
		}
		if(curr_line >from_line)
		{
			write(STDOUT_FILENO ,&buf,1);
		}
	}
	close(filedesc);
}

int main(int arg_n, char* arg_a[])
{

	int i = 0; // i for all for loops.
	int flag = 0;
	if(arg_n > 2)
			{
				flag = 1;
			}
	for(i = 1; i < arg_n; i++) // if there are no arguments the for loop will not be entered
	{
		if(*arg_a[i] == 45) // this detects the dash
		{

			read_input(flag); //==> dv <==
		}
		else
		{
			read_file(arg_a[i], flag);
		}
	}

	if(arg_n == 1)
	{
		read_input(0);
	}
	return 0;
}