#include "ch04.h" 
 char * myRead(const char *pathname,const char *mode,int n){ 
  FILE *fp; 
  char * buf; 
  char * buf1; 
  char count[4],buf2[4]; 
  int k = 0,sum = 0,myCount = 0,m=0; 
  int *num; 
  if((fp = fopen(pathname,mode)) == NULL) 
      err_exit("open file fiald!"); 
  if(fread(count,4,1,fp) == -1) 
      err_exit("read file fiald!"); 
  myCount = atoi(count); 
 buf =(char*) malloc(4*myCount); 
  num =(int *) malloc(myCount); 
  if(fread(buf,4,myCount,fp) == -1) 
err_exit("read file fiald!"); 
  if(n > myCount) 
      err_exit("the number greater than count"); 
  for(int i = 4;i <= 4*myCount;i+=4){ 
      k = 0; 
      for(int j = i-4;j<i;j++){ 
        buf2[k++] = buf[j]; 
      } 
      num[m++]=atoi(buf2); 
  } 
  for(int i = 0;i < n-1;i++){ 
     sum+=num[i]; 
  } 
 fseek(fp,sum,SEEK_CUR); 
  buf1 = (char*)malloc(sizeof(char)*num[n-1]); 
 fread(buf1,num[n-1],1,fp); 
  fclose(fp); 
  return buf1; 
 } 
 
 
 int main(){ 
  int n = 0; 
  char filename[50]; 
  printf("please input the filename\n"); 
  scanf("%s",filename); 
  printf("please input the number of item\n"); 
  scanf("%d",&n); 
  printf("%s\n",myRead(filename,"r",n)); 
  return 0; 
} 
