#include<stdio.h>
int main()
{
	double a,b;
	scanf("%lf",&a);
	if((int)a-a!=0)
		a=(int)a+1;
	if(a<=2)
		b=7;
	else if(a<=15)
		b=7+(a-2)*1.5;
	else if(a>15)
		b=7+13*1.5+(a-15)*2.1;
	printf("%lf",b);
	return 0;
}
