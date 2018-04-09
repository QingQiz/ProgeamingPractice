#include<stdio.h>
#include<string.h>
int main()
{
    char A[10][10];
    char *p[10],*t;
    int i=-1;
    while(i++<9) p[i]=A[i];
    for ( i = 0; i < 10; i++) {
        scanf("%s",A[i]);
    } 
    int k;
    for (int i = 0; i < 10; i++) {
        k=i;
        for (int j = i+1; j < 10; j++) {
            if(strcmp(p[k],p[j])>0)
                k=j;
        }
        t=p[i],p[i]=p[k],p[k]=t;
    }
    for (int i = 0; i < 10; i++) {
        printf("%s ",p[i]);
    }
    return 0;
}