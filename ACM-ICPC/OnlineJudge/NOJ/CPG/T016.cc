#include<stdio.h>
double a(int n)
{
	if(n==1)
		return 2;
	if(n==2)
		return 3;
	return a(n-1)+a(n-2);
}
double b(int n)
{
	if(n==1)
		return 1;
	if(n==2)
		return 2;
	return b(n-1)+b(n-2);
}
int main()
{
	int n=20;
	double sum=0;
	for(;n>=1;n--)
		sum+=a(n)/b(n);
	printf("%lf",sum);
	return 0;
}
