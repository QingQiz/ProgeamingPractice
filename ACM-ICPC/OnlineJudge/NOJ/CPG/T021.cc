#include<stdio.h>
int _7(int a)
{
	int b;
	do
	{
		b=a%10;
		a/=10;
		if(b==7)
			return 1;
	}
	while(a);
	return 0;
}
int main()
{
	int n;
	scanf("%d",&n);
	int i=7;
	for(;i<=n;i++)
	{
		if(_7(i)||!(i%7))
			printf("%d ",i);
	}
	return 0;
}