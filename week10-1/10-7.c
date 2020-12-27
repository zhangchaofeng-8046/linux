#include"ch10.h"
int main()
{
	int r1,r2,r3;
	r1=fork();
	if(r1==0)
	{
		printf("child 1 : pid=%d,ppid=%d\n",getpid(),getppid());
	}
	if(r1>0)
	{
		r2=fork();
		if(r2==0)
		{
			int y1,y2;
			y1=fork();
			if(y1==0)
			{
				printf("child 21: pid=%d,ppid=%d\n",getpid(),getppid());
				exit(0);
			}
			else if (y1>0)
			{
				y2=fork();
				if(y2==0)
				{
					printf("child 22 : pid=%d,ppid=%d\n",getpid(),getppid());
					exit(0);
				}
				else if(y2>0)
				{
					wait(NULL);
					wait(NULL);	
					printf("child 2 : pid=%d,ppid=%d,y1=%d,y2=%d\n",getpid(),getppid(),y1,y2);
					exit(0);
				}	
			}
		}
		else if(r2>0)
		{
			r3=fork();
			if(r3==0)
			{
				printf("child 3 : pid=%d,ppid=%d\n",getpid(),getppid());
				exit(0);
			}
			else if (r3>0)
			{
				wait(NULL);
				wait(NULL);
				wait(NULL);
				printf("parent : pid=%d,r1=%d,r2=%d,r3=%d\n",getpid(),r1,r2,r3);
				return 0;
			}
		}
	}
}
