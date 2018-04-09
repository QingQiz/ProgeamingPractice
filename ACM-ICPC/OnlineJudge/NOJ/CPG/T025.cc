#include<stdio.h>
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	int sum=10;
	for(;sum<=100;sum++)
	{
		if(sum%3==a&&sum%5==b&&sum%7==c)
		{
			printf("%d",sum);
			return 0;
		}
	}
	printf("%d",-1);
	return 0;
}
