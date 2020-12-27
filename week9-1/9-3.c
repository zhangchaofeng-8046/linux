#include"ch09.h"
int g=9;
int main()
{
	pid_t pid;
	int l=99;
	pid=vfork();
	if(pid<0)
	{
		perror("Fork Failed!\n");
		exit(-1);
	}
	else if(pid==0)
	{
		printf("child : ppid=%d , pid=%d\n",getppid(),getpid());
		printf("child : init g=%d,l=%d\n",g,l);
		g--;
		l++;
		printf("child : g=%d,l=%d\n",g,l);
		_exit(0);
	}
	else
	{
		wait(NULL);
		printf("parent : child pid=%d , pid=%d\n",pid,getpid());
		printf("parent : init g=%d,l=%d\n",g,l);
		g++;
		l--;
		printf("parent : g=%d,l=%d\n",g,l);
		return 0;
	}
}
