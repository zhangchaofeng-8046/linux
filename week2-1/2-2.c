#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(void){
	int ret;
	ret=write(0,"hello world!\n",13);
	printf("ret=%d\n",ret);
	return 0;
}
