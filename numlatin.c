#include <stdio.h>
int fact(int n)
{
	if(n==1)
		return 1;
	return n*fact(n-1);
}
int main()
{
	int t1,t2,m,n;
	printf("Enter the value of n:");
	scanf("%d",&n);
	t1=fact(n);
	t2=fact(n-1);
	m=t1*t2;
	printf("The number of latin squares are:%d",m);
}
