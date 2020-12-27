#include "ch04.h" 
struct { 
   char buf[10]; 
   char other[20]; 
 }buf; 
 int main(void){ 
   memset(buf.buf,0,sizeof(buf.buf)); 
   memset(buf.other,0,sizeof(buf.other));  
   gets(buf.buf); 
   printf("buf.buf=%s\n",buf.buf); 
   printf("buf.other = %s\n",buf.other); 
   return 0; 
 } 
