#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>

int main()
{
	FILE *A;
	FILE *B;

	pid_t Pid;
	Pid=fork();

	int fd_in;
	int fd_out;

	if(Pid==0)
	{
		fd_in = open("A.txt",O_RDONLY);
		fd_out = open("B.txt",O_WRONLY|O_CREAT|O_TRUNC,0644);

		dup2(fd_in,0);
		dup2(fd_out,1);

		execl("./P","P",(char *)0);

		close(fd_in);
		close(fd_out);
	}

	return 0;
}
