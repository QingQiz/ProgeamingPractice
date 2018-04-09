#include<stdio.h>
double fabs(double a)
{
	if(a<0)
		a=-1*a;
}
int main()
{
	double a,b;
	scanf("%lf,%lf",&a,&b);
	a=fabs(a);
	b=fabs(b);
	int m=10,n=0;
	if(a<=3&&a>=1&&b<=3&&b>=1)
		printf("%d",m);
	else
		printf("%d",n);
	return 0;
}
