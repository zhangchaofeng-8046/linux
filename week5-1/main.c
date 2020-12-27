#include "myfun.c"

int main(void){
    int check = 0;
    user users[1024];
    int n = 1024;
    printf("rand the data(1/0)");
    scanf("%d",&check);
    if(check == 1){
        n = randdat(users,n,10,"user.dat","r");
        printf("n=%d\n",n);
        save("user.dat","a",users,n,1);
        n = 1024;
    }
    printf("input the data(1/0)");
    scanf("%d",&check);
    if(check == 1){
        input(users,&n);
        save("user.dat","a",users,n,1);
    }
    printf("sort?(/1/0/-1)");
    scanf("%d",&check);
    if(check==1 || check == 0)
        mysort("user.dat",check);
    n = 1024;
    n = save("user.dat","r",users,n,0);
    printf("n=%d\n",n);
    output(users,n);

  return 0;
}