#include<stdio.h>
void scan(int a)
{
	int i=1,j=2;
	for(;;)
	{
		if(a%j==0)
			break;
		j++;
	}
	j=a/j;
	for(;i<j;i++)
		if(!(a%i))
			printf("%d+",i);
	printf("%d",j);
	printf("\n");
}
int WaQ(int a)
{
	int sum=0,i;
	for(i=1;i<a;i++)
			if(!(a%i))
				sum+=i;
	if(a==sum)
		return 1;
	else
		return 0;
}
int main()
{
	int a=1;
	for(;a<=1000;a++)
		if(WaQ(a))
		{
			printf("%d=",a);
			scan(a);
		}
	return 0;
}