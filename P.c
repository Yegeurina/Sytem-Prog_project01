#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>

void err_sys(const char* x)
{
	perror(x);
	exit(1);
}

int main(void)
{
	int c;

	while((c=getc(stdin))!=EOF)
	{
		if(putc(c,stdout)==EOF)
		{
			err_sys("output error");
		}
	}

	if(ferror(stdin))
	{
		err_sys("input error");
	}


	return 0;
}
