#include <stdio.h>
int sum(int i,int base)
{
    int sum=0;
    while(i!=0){
        sum+=i%base;
        i/=base;
    }
    return sum;
}
int main()
{
    int n=2000;
    for(;n<3000;n++){
        if(sum(n,10)==sum(n,12)&&sum(n,10)==sum(n,16))
            printf("%d\n",n);
    }
    return 0;
}