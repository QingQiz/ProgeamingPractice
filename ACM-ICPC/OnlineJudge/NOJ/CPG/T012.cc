#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int flg,i=1,sum,k;
	for(;;)
	{
		k=i;
		sum=0;
		for(flg=1;flg<=n;flg++)
		{
			sum+=k;
			k+=2;
		}
		if(sum==n*n*n)
			break;
		i+=2;
	}
	printf("%d*%d*%d=%d=",n,n,n,n*n*n);
	for(k=1;k<=n-1;k++)
	{
		printf("%d+",i);
		i+=2;
	}
	printf("%d",i);
	return 0;
}
