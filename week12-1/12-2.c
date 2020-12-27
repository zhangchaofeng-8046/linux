#include"ch12.h"
int main()
{
	int fd1[2],fd2[2],i;
	char buf[100];
	memset(buf,0,sizeof(buf));
	pid_t k;
	pipe(fd1);
	pipe(fd2);
	k=fork();
	if(k<0)
	{
		perror("fork error!\n");
		exit(-1);
	}
	else if(k==0)
	{
		close(fd1[1]);
		close(fd2[0]);
		sleep(1);
		i=read(fd1[0],buf,sizeof(buf));
		if(i==0)
		{
			printf("child read failed!\n");
			exit(0);
		}
		else
		{
			fprintf(stdout,"read from pipe : %s\n",strlen(buf));
			sprintf(buf,"child recive from parent %d byte!",strlen(buf));
			write(fd2[1],buf,sizeof(buf));
			exit(1);
		}
	}
	else
	{
		close(fd1[0]);
		close(fd2[1]);
		sprintf(buf,"%d say hello to %d!",getpid(),k);
		i=write(fd2[1],buf,sizeof(buf));
		if(i==0)
		{
			printf("parent write failed!\n");
		}
		else
		{
			printf("write from pipe : %s\n",buf);
		}
		read(fd2[0],buf,sizeof(buf));
		printf("%s\n",buf);
		wait(NULL);
		exit(0);
	}
}
