#include"ch12.h"
int main()
{
	int fd[2],i;
	char buf[100];
	memset(buf,0,sizeof(buf));
	pid_t k;
	pipe(fd);
	k=fork();
	if(k<0)
	{
		perror("fork error!\n");
		exit(-1);
	}
	else if(k==0)
	{
		close(fd[1]);
		dup1(fd[0],0);
		execlp("dup1","dup1",NULL);
		close(fd[0]);
	}
	else
	{
		close(fd[0]);
		sprintf(buf,"%d say hello to %d!",getpid(),k);
		i=write(fd[1],buf,sizeof(buf));
		if(i==0)
		{
			printf("parent write failed!\n");
		}
		else
		{
			printf("write from pipe : %s\n",buf);
		}
		wait(NULL);
		exit(0);
	}
}
