#include"ch08.h"
int main()
{
	pid_t p1,f1;
	p1=getpid();
	f1=getppid();
	printf("jcurrent process pid=%d,ppid=%d\n",p1,f1);
	sleep(10);
	return 0;
}
