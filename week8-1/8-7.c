#include"ch08.h"
int g_int=1;
int main()
{
	pid_t ret;
	int local_int=1;
	int *pt=(int *)malloc(sizeof(int));
	ret=fork();
	if(ret==0)
	{
		g_int=999;
		local_int=888;
		printf("Child g_int=%d,local_int=%d,*pt=%d\n",g_int,local_int,*pt);
		free(pt);
		printf("Child : ret = %d\n",ret);
		printf("Child pid = %d,ppid= %d\n",getpid(),getppid());
		sleep(10);
		exit(0);
	}
	else if(ret<0)
	{
		perror("fork failed!\n");
		exit(-1);
	}
	else
	{
		//sleep(3);
		waitpid(ret,NULL,0);
		printf("After Child exit,g_int=%d,local_int=%d,*pt=%d\n",g_int,local_int,*pt);
		printf("Parent : ret =%d\n",ret);
		printf("Parent : pid =%d,ppid= %d\n",getpid(),getppid());	
		return 0;
	}
}
