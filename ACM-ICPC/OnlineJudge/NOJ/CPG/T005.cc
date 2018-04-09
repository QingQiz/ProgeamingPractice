#include<stdio.h>
int main()
{
	int a,b,i,sum=0,aa;
	scanf("%d",&a);
	aa=a;
	do
	{
		b=a%10;
		sum=10*sum+b;
		a/=10;
	}
	while(a!=0);
	if(sum==aa)
		printf("yes");
	else
		printf("no");
	return 0;
}
