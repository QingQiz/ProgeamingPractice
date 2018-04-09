#include<stdio.h>
int main()
{
    int maxi;
    int N;
    int flg=1;
    int i=0;
    scanf("%d",&N);
    int A[N];
    for(;i<N;i++)
        scanf("%d",&A[i]);
    int j,pro;
    for(i=0;i<N;i++)
    {    
        pro=A[i];
        if(flg==1)
        {
           maxi=pro;
           flg=0;
        }
        if(pro>maxi)
            maxi=pro;
        for(j=i+1;j<N;j++)
        {
            pro*=A[j];
            if(pro>maxi)
                maxi=pro;
        }
    }
    printf("%d\n",maxi);
    return 0;
}