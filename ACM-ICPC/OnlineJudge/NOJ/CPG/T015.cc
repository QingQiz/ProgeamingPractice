#include <stdio.h>
int prineQ(int a)
{
	int i=2;
	for(;i<a;i++)
	{
		if(a%i==0)
			return 0;
	}
	return 1;
}
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(;a<=b;a++)
	{
		if(prineQ(a))
			printf("%d ",a);
	}
	return 0;
}
