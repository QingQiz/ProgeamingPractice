#include <stdio.h>
int Factorial(int i)
{
    int n=1,ans=1;
    for(;n<=i;n++)ans*=n;
    return ans;
}
int main()
{
    int N,i,sum=0;
    scanf("%d",&N);
    for(i=1;;i++)if(Factorial(i)>=N)break;
    if(Factorial(i)==N){
        printf("YES");
        return 0;
    }
    i--;
    sum+=Factorial(i);
    for(int j=1;j<i;j++){
        if(Factorial(i-j)+sum<=N){
            sum+=Factorial(i-j);
        }
        if(sum==N){
            printf("YES");
            return 0;
        }
    }
    printf("NO");
    return 0;
}