#include "my.h"
user* input(user *users,int *n){
    int next = 1,i = 0,check = 1;
    while(next==1 && i < *n){
        check = 1;
        while(check){
            printf("input the id:");
            scanf("%d",&users[i].id);
            check = checkId(users,i,"user.dat","r",check);
        }
        check = 2;
        while(check){
            printf("input the name:");
            scanf("%s",users[i].name);
            check = checkId(users,i,"user.dat","r",check);
        }
        check = 3;
        while(check){
            printf("input the htel:");
            scanf("%s",users[i].htel);
            check = checkId(users,i,"user.dat","r",check);
        }
        check = 4;
        while(check){
            printf("input the tel:");
            scanf("%s",users[i].tel);
            check = checkId(users,i,"user.dat","r",check);
        }
        printf("Are you want to write the next(1/0):");
        scanf("%d",&next);
        i++;
    }
    *n = i;
    return users;
}
int randdat(user *temp,int n,int num,char *filename,char *mode){
    srand(time(NULL));
    int check = 1,i;
    for(i = 0; i < n && i<num;i++){
        while(check){
            int id = rand()%4294967296;
            temp[i].id = id;
            check = checkId(temp,i,filename,mode,1);
        }
        check = 2;
        while(check){
            int m = rand()%nname;
            strcpy(temp[i].name,name[m]);
            check = checkId(temp,i,filename,mode,2);
        }
        check = 3;
        while(check){
            int m = rand()%nhtel;
            strcpy(temp[i].htel,htel[m]);
            check = checkId(temp,i,filename,mode,3);
        }
        check = 4;
        while(check){
            int m = rand()%ntel;
            strcpy(temp[i].tel,tel[m]);
            check = checkId(temp,i,filename,mode,4);
        }

    }
    if(i!=0){
        return i;
    }
    return 0;
}
int checkId(user *temp,int tn,char *filename,char *mode,int id){
    user users[1024];
    int n = 1024;
    char item[4];
    if(id == 1){
        if(temp[tn].id > 4294967295 || temp[tn].id < 0)
            return 1;
        n = save(filename,mode,users,n,0); 
        for(int i = 0;i < n;i++){
            if(temp[tn].id == users[i].id)
                return 1;
        }
        for(int i = 0;i<tn;i++){
            if(temp[tn].id == temp[i].id)
                return 1;
        }
    }
    else if(id ==2){
    if(temp[tn].name[0]<'A'|| temp[tn].name[0]>'Z'|| strlen(temp[tn].name)>7)
        return 2;
    }
    else if(id == 3){
    if(strlen(temp[tn].htel) <10 ||strlen(temp[tn].htel) >11 ||strchr(temp[tn].htel,'-')==NULL )
        return 3;
    }
    else if(id ==4){
    if(strlen(temp[tn].tel)!=11)
        return 4;
    strncpy(item,temp[tn].tel,3);
    if(strcmp(item,"138")||strcmp(item,"130")||strcmp(item,"131")||strcmp(item,"130")||strcmp(item,"159")||strcmp(item,"181"))
        return 0;
    else
        return 4;
    }
    return 0;

}
int save(char *filename,char *mode,user *users,int n,int rw){
    FILE *fp = NULL;
    int res,flag = 0,i,re = 0;
    char buf[1024];
    if(access(filename, 0) == -1 && strcmp(mode,"r") == 0)
        return 0;
    fp = fopen(filename,mode);
    if(fp == NULL){
        printf("open the file(%s) failed!\n",filename);
        exit(-1);
    }
    if(rw == 1){
        /* if(flag){
             fprintf(fp,"userid\tname\thtel\ttel\n");
         }*/
         for(i = 0;i < n;i++){
             res = fprintf(fp,"%d\t%s\t%s\t%s\n",users[i].id,users[i].name,users[i].htel,users[i].tel);
             if(res == EOF){
             printf("write the data to file failed!\n");
             exit(-1);
            }
         }
    }else{
      //  fgets(buf,sizeof(buf),fp);
        fseek(fp,0,SEEK_SET);
        int my = 0;
        for(i = 0;i < n;i++){
            re = i;
            if((my = fscanf(fp,"%d\t%s\t%s\t%s\n",&users[i].id,users[i].name,users[i].htel,users[i].tel)) == EOF){
                break;
            }
        }
    }
    fclose(fp);
    return re;
}
int cmp(const void *p1,const void *p2){
    return strcmp(((user *)p1)->name,((user*)p2)->name);
}
int cmp2(const void *p1,const void *p2){
    return strcmp(((user *)p2)->name,((user*)p1)->name);
}  
void mysort(char * filename,int mode){
    user users[1024];
    int n = 1024;
    n = save(filename,"r",users,n,0); 
    if(mode == 0){   
         qsort(users,n,sizeof(user),cmp);  
    }
    else if(mode == 1)
         qsort(users,n,sizeof(user),cmp2);
    if(mode == 1 || mode == 0)
         save(filename,"w",users,n,1);
    return;
}

void output(user* users,int n){
    printf("userid\tname\thtel\ttel\n");
    for(int i = 0;i < n;i++){
    printf("%d\t%s\t%s\t%s\n",users[i].id,users[i].name,users[i].htel,users[i].tel);
    }

}
