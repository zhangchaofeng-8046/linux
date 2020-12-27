#include"ch12.h"
int main(int argc,char **argv)
{
	int i;
	int fd;
	fd=open("./test2.dat",O_CREAT|ORDWR|O_APPEND,0644);
	close(1);
	dup(fd);
	printf("test : pid=%d,ppid=%d",getpid(),getppid());
	for(i=0;i<argc;i++)
		printf("argv[%d] : %d\n",i,argv[i]);
	return 0;
}
