#include <stdio.h>
int t[100][100];
int bounded_knapsack(int n,int val[],int wt[],int w )
{
	int i,j;
	for(i=0;i<(n+1);i++)
		for(j=0;j<(w+1);j++)
		{
			if(i==0 || j==0)
				t[i][j]=0;
			else
			{
				if(wt[i-1]<=j)
				{
					t[i][j]=max(val[i-1]+t[i][j-wt[i-1]],t[i-1][j]);
				}
				else
				{
					t[i][j]=t[i-1][j];
				}
			}
		}
	return t[n][w];
}
int max(int a,int b)
{
	return (a>b?a:b);
}
int main()
{
	int W = 8,ans;
    int  val[4] = {10, 40, 50, 70};
    int wt[4]  = {1, 3, 4, 5};
	int n=4;
	ans=bounded_knapsack(n,val,wt,W);
	printf("%d",ans);
	return 0;
}
