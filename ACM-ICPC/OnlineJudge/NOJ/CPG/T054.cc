#include <stdio.h>
int main()
{
    char A[20];
    int flg=0;
    for (int i = 0; i < 20; i++) {
        scanf("%c",A+i);
        flg++;
        if (A[i]=='\n') {
            A[i]='\0';
            flg--;
            break;
        }
    }
    flg/=2;
    char *start,*end,t;
    start=A,end=A;
    while(*++end);
    end-=flg;
    int k;
    for (int i = 0; i < flg; i++) {
        k=i;
        for (int j = i+1; j < flg; j++) {
            if(start[k]<start[j])
                k=j;
        }
        t=start[i],start[i]=start[k],start[k]=t;
    }
    for (int i = 0; i < flg; i++) {
        k=i;
        for (int j = i+1; j < flg; j++) {
            if(end[k]>end[j])
                k=j;
        }
        t=end[i],end[i]=end[k],end[k]=t;
    }
    start=A,end=A;
    while(*++end);
    end-=flg;
    for (int i = 0; i < flg; i++) {
        t=start[i],start[i]=end[i],end[i]=t;
    }
    printf("%s",A);
}