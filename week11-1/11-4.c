#include"ch11.h"
int main()
{
	pid_t pid1;
	pid1=fork();
	if(pid1<0)
	{
		perror("fork failed!\n");
		exit(-1);
	}
	else if(pid1==0)
	{
		char *argv[]={"./test","hello",NULL};
		printf("child1 : pid=%d,ppid=%d,re=%d\n",getpid(),getppid(),pid1);
		execve("./test",argv,NULL);
		exit(0);
	}
	else
	{
		pid_t pid2;
		pid2=fork();
			if(pid2<0)
			{
				perror("fork failed!\n");
				exit(-1);
			}
			else if(pid2==0)
			{
				printf("child2 :pid=%d,ppid=%d,re=%d\n",getpid(),getppid(),pid2);
				while(1);
				exit(0);
			}
		else
		{
			int s1,s2,r1,r2;
			r1=waitpid(pid1,&s1,0);
			r2=waitpid(pid2,&s2,WNOHANG);
			if(WIFEXITED(s1))
				printf("child 1 exit nomaly!exit code %d\n",WEXITSTATUS(s1));
			else
				printf("child 1 exit abnomaly!exit with signal %d\n",WTERMSIG(s1));
			if(WIFEXITED(s2))
				printf("child 2 exit nomaly!exit code %d\n",WEXITSTATUS(s2));
			else
				printf("child 2 exit abnomaly!exit with signal %d\n",WTERMSIG(s2));

			
			printf("parent ended!\n");
			
			return 0;
		}
	}
}

