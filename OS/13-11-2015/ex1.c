#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	char buff[2000];
	int fd = open("read.c", O_RDONLY);
	int status;

	while ((status = read(fd, buff, 2000)) > 0)
	{
		int bytes_written = 0;
		while (bytes_written < status)
		{
			int status_write = write(STDOUT_FILENO, buff + bytes_written, status - bytes_written);

			bytes_written += status_write;
		}
	
		close(fd);

		return 0;
	}
}