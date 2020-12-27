#include "ch04.h"

int main(void){
  int fd;
  if((fd = open("myoutput",O_WRONLY|O_CREAT,0644)) == -1)
      err_exit("myoutput");
  if(dup2(fd,STDOUT_FILENO) == -1)
      err_exit("redirect standard output fialed");
  printf("this is atest program for redirect\n");
  close(fd);
  return 0;
}
