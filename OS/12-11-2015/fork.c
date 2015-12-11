#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() 
{
	pid_t pid = fork();
	if (pid == 0)
	{
		printf("%d, Hi from child!\n", pid);
		return 42;
	}
	else if (pid > 0)
	{
		int status;
		printf("%d, Hi from parent!\n");
		sleep(30) // zaspiva za 30 sek 
		waitpid(pid, &status, 0);
		printf("%d, Hi from child!\n", WEXITSTATUS(status));
	}
return 0;
}
