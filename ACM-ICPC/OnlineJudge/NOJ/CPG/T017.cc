#include<stdio.h>
double pow(double a,int i)
{
	double j=1;
	for(;i>=1;i--)
		j*=a;
	return j;
}
double mo(double A,double p,int n,int a)
{
	return A*pow((1+p*12*n),a);
}

int main()
{
	int a,b,c,d,e;
	int n1,n2,n3,n5,n8;
	double A,mmm=0;
	for(e=0;e<3;e++)
		for(d=0;d<6;d++)
			for(c=0;c<7;c++)
				for(b=0;b<11;b++)
					for(a=0;a<21;a++)
					{
						if(a+2*b+3*c+5*d+8*e==20)
						{
							A=2000;
							A=mo(A,0.0084,8,e);
							A=mo(A,0.0075,5,d);
							A=mo(A,0.0069,3,c);
							A=mo(A,0.0066,2,b);
							A=mo(A,0.0063,1,a);
							if(mmm<A)
								mmm=A;
							if(A==mmm)
								n1=a,n2=b,n3=c,n5=d,n8=e;
						}
					}
	printf("%d %d %d %d %d\n",n8,n5,n3,n2,n1);
	printf("%.2lf",mmm);
	return 0;
}
