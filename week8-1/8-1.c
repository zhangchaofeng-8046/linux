#include"ch08.h"
static int x1=0,x2;
int y;
int main()
{
	int x3=0xffffffff,x4;
	static int x5=0x11111111;
	int a[10];
	int *pt=(int *)malloc(65536*65536*65536*65536*sizeof(long));
	printf("address of y  :%x\n",&y);
	printf("address of x1 :%x, x2: %x\n",(unsigned int)&x1,(unsigned int)&x2);
	printf("address of x3 :%x, x4: %x\n",(unsigned int)&x3,(unsigned int)&x4);
	printf("address of x5 :%x,  a: %x\n",(unsigned int)&x5,(unsigned int)a);
	printf("address of pt :%x,%d\n",(unsigned int)pt,sizeof(pt));
	return 0;
}
