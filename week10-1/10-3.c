#include"ch10.h"
int main()
{
	//char *argv[]={"./test.c","hello","world",NULL};
	int i;
	printf("10-2 : pid=%d,ppid=%d\n",getpid(),getppid());
	i=execle("./test","./test","Hello","world","2020","11","23",NULL,NULL);
	if(i==-1)
	{
		perror("execve failed!\n");
		exit(1);
	}
	printf("after calling!\n");
	return 0;
	
	
}
