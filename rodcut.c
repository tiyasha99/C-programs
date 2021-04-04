#include <stdio.h>
int t[100][100];
int rod_cutting(int length,int price[])
{
	int i,j,arr[length];
	for(i=1;i<=length;i++)
		arr[i-1]=i;
	for(i=0;i<(length+1);i++)
		for(j=0;j<(length+1);j++)
		{
			if(i==0 || j==0)
				t[i][j]=0;
			else if(arr[i-1]<=j)
			{
				t[i][j]=max(price[i-1]+t[i][j-arr[i-1]],t[i-1][j]);
			}
			else
			 t[i][j]=t[i-1][j];
		}
	return t[length][length];
					
}
int max(int a ,int b)
{
	return (a>b?a:b);
}
int main()
{
	int price[8]={1,5,8,9,10,17,17,20};
	int length=8;
	int ans;
	ans=rod_cutting(length,price);
	printf("%d",ans);
}
