#include <stdio.h> 
#include <float.h> 
 int main(void){ 
   int a = 1; 
   a = a << sizeof(int)*8 - 1; 
   printf("int_Max=%d\n",-a-1); 
   printf("int_Min=%d\n",a); 
   printf("float_MAX=%e\n",FLT_MAX); 
   printf("float_MIN=%e\n",FLT_MIN); 
   printf("double_MAX=%e\n",DBL_MAX); 
   printf("double_MIN=%e\n",DBL_MIN);    
   return 0; 
 } 
