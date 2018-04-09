#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int N,k,i,j;
    scanf("%d",&N);
    char **p,MID[25];
    p=(char**)malloc(N*sizeof(char*));
    for(i=0;i<N;i++)
        p[i]=(char*)malloc(25*sizeof(char));
    for(i=0;i<N;i++)
        scanf("%s",p[i]);
    for(i=0;i<N;i++){
        k=i;
        for(j=i+1;j<N;j++){
            if(strlen(p[j])<strlen(p[k]))
                k=j;
        }
        strcpy(MID,p[i]);
        strcpy(p[i],p[k]);
        strcpy(p[k],MID);
    }
    for(i=0;i<N;i+=2)printf("%s ",p[i]);
    if((N-1)%2==0){
        for(i=N-2;i>1;i-=2)printf("%s ",p[i]);
    }
    else{
        for(i=N-1;i>1;i-=2)printf("%s ",p[i]);
    }
    printf("%s",p[1]);
    for(i=0;i<N;i++)free(p[i]);
    free(p);
    return 0;
}