#include<stdio.h>
double summ(int n,int m)
{
	double sum=0;
	int i=n;
	for(;i<=m;i++)
	{
		sum+=1.0/i*1.0/i;
	}
	return sum;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	if(m<=n||m>=1000000||n>=1000000)
		return -1;
	printf("%.5lf",summ(n,m));
	return 0;
}
