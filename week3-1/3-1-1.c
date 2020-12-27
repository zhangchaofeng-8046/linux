#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
int main(void){
  int fd = open("./test.txt",O_CREAT,0644,"test");
   printf("file descriptor = %d \n",fd);
   close(fd);
   return 0;
 }
