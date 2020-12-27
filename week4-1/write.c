#include "ch04.h"

int main(void){
  int n,fd;
  char buf;
  fd = open("./file.test",O_CREAT|O_RDWR,0644);
  srand(time(0));
  n = rand()%26;
  buf = (char)('a' + n);
  write(fd,&buf,1);
  sleep(50);
  lseek(fd,10,SEEK_SET);
  srand(time(0));
  n = rand();
  buf = (char)('a' + n);
  write(fd,&buf,1);
  sleep(50);
  close(fd);
  return 0;
}
