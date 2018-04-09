#include<stdio.h>
int main()
{
	int a,b,c,r;
	scanf("%d%d%d",&a,&b,&c);
	r=a;
	if(r<b)
		r=b;
	if(r<c)
		r=c;
	printf("%d",r);
	return 0;
}
