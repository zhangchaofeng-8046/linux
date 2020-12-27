#include"ch08.h"
int main()
{
	int i,*pt=NULL;
	for(i=0;i<1024*1024;i++)
	{
		pt=(int *)malloc(i*1024*sizeof(int));\
		if(pt!=NULL)
		{
			printf("System allocate %dKB\n",i);
		}
		else
		{
			perror("allocate finished\n");
		}
	}	
	return 0;
}
