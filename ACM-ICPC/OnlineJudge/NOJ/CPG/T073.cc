#include<stdio.h>
#include <stdlib.h>
int main()
{
    int n,m,*p;
    scanf("%d%d",&n,&m);
    p=(int*)malloc(n*sizeof(int));
    if(p!=NULL){
        for(int i=0;i<n;i++)scanf("%d",p+i);
        int t,k,test;
        test=p[m];
        for(int i=0;i<n;i++){
            k=i;
            for(int j=i+1;j<n;j++){
                if(p[j]>p[k])k=j;
            }
            t=p[i],p[i]=p[k],p[k]=t;
        }
        for(int i=0;i<n;i++){
            if(p[i]==test){
                k=i;
                break;
            }
        }
        printf("%d",k+1);
        free(p);
    }
    return 0;
}