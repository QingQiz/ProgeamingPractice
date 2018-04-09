#include <stdio.h>
int main()
{
    int H,sum=0,cont=0;
    scanf("%d",&H);
    while(1){
        cont++;
        sum+=10;
        if(sum>=H)break;
        sum-=5;
    }
    printf("%d",cont);
    return 0;
}