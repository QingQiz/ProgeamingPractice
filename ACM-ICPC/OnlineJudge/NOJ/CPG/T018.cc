#include<stdio.h>
double f(double A,double a);
double abs(double a)
{
	if(a<0)
		return -a;
	else
		return a;
}
int main()
{
	double a;
	scanf("%lf",&a);
	double A=1;
	for(;;)
	{
		if(abs(A-f(A,a))<=1E-6)
			break;
		A=f(A,a);
	}
	printf("%.5lf",A);
	return 0;
}
double f(double A,double a)
{
	return 1.0/2*(A+a/A);
}

