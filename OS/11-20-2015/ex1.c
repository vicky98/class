#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
	char buff[200], buff2[200];
	int fd = open("read.c", O_RDONLY);
	int status, status2;
	
	if (fd < 0)
	{
		perror("file 1: ");
		return 0;
	}
	
	int fd2 = open("read.c", O_RDONLY);
	
	if (fd2 < 0)
	{
		perror("file 2: ");
		return 0;
	}
	
	while((status = read(fd, buff, 200)) > 0)
	{
		int bytes_read = 0;
		
		while(bytes_read < status)
		{
			status2 = read(fd2, buff2 + bytes_read, status);
		
			if (status2 == 0)
			{
				printf("diff\n");
				return 0;
			}
			
			int i;
		
			for(i = bytes_read; i < status2 + bytes_read; i++)
			{
				if (buff[i] != buff2[i])
				{
					printf("diff\n");
					return 0;
				} 
				
				bytes_read += status2;
			}
		}
	}

	status2 = read(fd2, buff2, 1);

	if (status2 > 0)
	{
		printf("diff\n");
		return 0;
	}

	close(fd); 
	close(fd2);
}