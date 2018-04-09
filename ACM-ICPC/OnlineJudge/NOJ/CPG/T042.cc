#include <stdio.h>
int find(int A[],int b,int N)
{
    int first=0,end=N-1;
    int mid;
    while(first<=end)
    {
        mid=(first+end)/2;
        if(A[mid]>b)
            end=mid-1;
        else if(A[mid]<b)
            first=mid+1;
        else 
            return mid;
    }
    return -1;
}
int main()
{
    int N;
    scanf("%d",&N);
    int A[N],b;
    int i=0;
    for(;i<N;i++)
        scanf("%d",&A[i]);
    scanf("%d",&b);
    int ans;
    ans=find(A,b,N);
    if(ans==-1)
        printf("null");
    else {
        printf("%d",ans);
    }
    return 0;
}