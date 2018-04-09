#include<stdio.h>
int _2_s(int a,int b)
{
	int A[5],B[5];
	int i=0;
	do
	{
		A[i]=a%10;
		B[i]=b%10;
		a/=10;
		b/=10;
		i+=1;
	}
	while(i<5);
	int m,n;
	for(m=0;m<5;m++)
		for(n=0;n<5;n++)
			if(A[m]==B[n]||A[m]==A[n]&&m!=n||B[m]==B[n]&&m!=n)
				return 0;
	return 1;
}
int main()
{
	int n;
	scanf("%d",&n);
	int a=12345,b;
	for(;a<98766;a++)
	{
		if(a%n==0)
		{
			b=a/n;
			if(_2_s(a,b))
				printf("%05d/%05d=%d\n",a,b,n);
		}
	}
	return 0;
}
