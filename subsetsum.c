#include <stdio.h>
int t[100][100];
int subset_sum(int arr[],int sum,int n)
{
	int i,j;
	for(i=0;i<(n+1);i++)
		for(j=0;j<(sum+1);j++)
		{
			if(i==0 && j!=0)
				t[i][j]=0;
			else if(j==0)
				t[i][j]=1;
			else
			{
				if(arr[i-1]<=j)
					t[i][j]=t[i][j-arr[i-1]] || t[i-1][j];
			}
		}
	if(t[n][sum]==1)
		printf("True");
	else
		printf("False");
}
int main()
{
	int arr[5]={2,3,7,8,10};
	int n=5;
	int sum=11;
	subset_sum(arr,sum,n);
	return 0;
}
