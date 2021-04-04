#include <stdio.h>
int t[100][100];
int count_subset_sum(int arr[],int n,int s)
{
	int i,j;
	for(i=0;i<(n+1);i++)
	{
		for(j=0;j<(s+1);j++)
		{
			if(i==0 && j!=0
			)
				t[i][j]=0;
			if(j==0)
				t[i][j]=1;
			else
			{
				if(arr[i-1]<=j)
					t[i][j]=t[i-1][j-arr[i-1]]+t[i-1][j];
				else
					t[i][j]=t[i-1][j];
			}
		}
	}
	/*for(i=0;i<(n+1);i++)
	{
		printf("\n");
		for(j=0;j<(s+1);j++)
			printf("%d\t",t[i][j]);
	}*/
	return t[n][s];
}
int count_subset_diff(int sum,int diff)
{
	int sum_s1=(diff+sum)/2;
	return sum_s1;
}
int main()
{
	int arr[4]={1,1,2,3};
	int n=4,s,ans,i,sum=0,diff=1;
	for(i=0;i<4;i++)
		sum+=arr[i];
	s=count_subset_diff(sum,diff);
	ans=count_subset_sum(arr,n,s);
	printf("%d",ans);
}
