#include "ch03.h"

int main(void){
  FILE * fp =NULL;
  char buf[80];
  printf("open and create test_file.\n");
  if((fp = fopen("./test_file","w")) == NULL){
    perror("fopen failed!\n");
    exit(1);
  }
  printf("wrting string to test_file.\n");
  fputs("test date",fp);
  if((fp = freopen("./test_file","r",fp)) == NULL){
    perror("freopen failed !\n");
  }
  printf("read stirng from test_file:\t");
  fgets(buf,sizeof(buf),fp);
  printf("this string is %s\n",buf);
  fclose(fp);

  return 0;
}

