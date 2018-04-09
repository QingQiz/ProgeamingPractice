#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double area(double Ri)
{
    if(Ri>1)
        return pow((Ri*Ri-1),0.5)*2*2;
    else 
        return 2*Ri*Ri;
}
int main()
{
    int N,k;
    scanf("%d",&N);
    double *p,mid,sum=0;
    p=(double*)malloc(N*sizeof(double));
    for(int i=0;i<N;i++){
        scanf("%lf",&p[i]);
        p[i]=area(p[i]);
    }
    for(int i=0;i<N;i++){
        k=i;
        for(int j=i+1;j<N;j++){
            if(p[j]>p[k])k=j;
        }
        mid=p[i],p[i]=p[k],p[k]=mid;
    }
    //for(int i=0;i<N;i++)printf("%lf ",p[i]);
    for(int i=0;i<N;i++){
        sum+=p[i];
        if(sum>=40){
            printf("%d",i+1);
            break;
        }
    }
    free(p);
    return 0;
}