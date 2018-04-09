#include<stdio.h>
int primeQ(int a)
{
	int i;
	i=2;
	for(;i<a;i++)
		if(a%i==0)
			return 0;
	return 1;
}
int main()
{
	int i=800,j=0,k=1,Sum=0;
	for(;i>=500;i--)
	{
		if(primeQ(i))
		{
			j++;
			Sum+=k*i;
			k*=-1;
		}
	}
	printf("%d ",j);
	printf("%d",Sum);
	return 0;
}
