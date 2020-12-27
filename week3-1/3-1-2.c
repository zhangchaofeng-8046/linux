#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
int main(void)
{
	FILE *fp=fopen("./test.txt","w");
	char buf[80];
	int ret=0;
	memset(buf,0,sizeof(buf));
	fgets(buf,sizeof(buf),stdin);
	printf("\nthe string is %s \n",buf);
	ret=fwrite(buf,sizeof(buf),1,fp);
	printf("number of item write to file = %d\n",ret);
	fclose(fp);
	return 0;
}

