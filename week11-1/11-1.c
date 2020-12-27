#include"ch11.h"
int main()
{
	pid_t pid;
	pid=fork();
	if(pid<0)
	{
		perror("fork failed!\n");
		exit(-1);
	}
	else if(pid==0)
	{
		char *argv[]={"./test","hello",NULL};
		printf("child : pid=%d,ppid=%d,re=%d\n",getpid(),getppid(),pid);
		execve("./test",argv,NULL);
		exit(99);
	}
	else
	{
		int s,r;
		r=wait(&s);
			if(WIFEXITED(s))
			{
			printf("exit code=%d,wait pid=%d\n",WEXITSTATUS(s),r);
			}
			else{
				printf("child oricess stoped with signal! %d\n",WTERMSIG(s));
			}
		return 0;
	}
}

