#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
struct user{
int id;
char name[8];
char htel[12];
char tel[12];
};
const int nname = 8;
const int nhtel = 3;
const int ntel = 4;
char name[8][3]={"Hxl","Zcf","Tbb","Hll","Asd","Fgh","Kqw","Xsd"};
char htel[3][11]={"088-1234568","012-1234567","034-3456789"};
char tel[4][11]={"13812345671","13112345671","15912345671","13312345671"};
typedef struct user user;
void output(user* users,int n);
int save(char *filename,char *mode,user *users,int n,int rw);
user* input(user *users,int *n);
int checkId(user*,int,char *,char*,int);
void mysort(char * filename,int mode);
int cmp(const void *p1,const void*p2);    
int cmp2(const void *p1,const void*p2);
int randdat(user *temp,int n,int num,char *filename,char *mode);
