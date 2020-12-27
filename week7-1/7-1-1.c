#include"ch07.h"
int main(int argc,char *argv[])
{	
	int x,y;
	if(argc!=3){
		printf("Arguments failed!\n");		
	}
	x=atoi(argv[1]);
	y=atoi(argv[2]);
	printf("x+y=%d\n",x+y);
	for(int i=0;i<argc;i++)
		printf("argv[%d] : %s\n",i,argv[i]);
	return 0;
}
