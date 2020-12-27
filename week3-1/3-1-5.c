#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
	FILE *fp=fdopen(1,"w+");
	fprintf(fp,"%s\n","hello!");
	fclose(fp);
}

