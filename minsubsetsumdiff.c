#include <stdio.h>
#include <stdlib.h>
int t[100][100];
int d[100];
#define MAX 2000
void subset_sum(int arr[],int sum,int n)
{
	int i,j,k=0;
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
					t[i][j]=t[i-1][j-arr[i-1]] || t[i-1][j];
				else
					t[i][j]=t[i-1][j];
			}
		}
	for(i=0;i<(sum+1);i++)
		{
			if(t[n][i]==1)
				d[k++]=i;
		}
}
int min_subset_sum_diff(int arr[],int s,int n)
{
	int i,mn,flag,sum;
	mn=MAX;
	//printf("%d",mn);
	flag=(s%2==0?1:0);
	//printf("flag=%d",flag);
	sum=s;
	if(flag==0)
		s-=1;
	//printf("s=%d",s);
	for(i=0;i<=s/2;i++)
		{
			mn=min(mn,abs(sum-2*d[i]));
			//printf("mn=%d\n",mn);
		}
		
/*	for(i=0;i<(s+1);i++)
		printf("%d\t",d[i]);*/
	return mn;
}
int min(int a,int b)
{
	return (a<b?a:b);
}
int main()
{
	int arr[4]={1,6,11,5};
	int n,N,i,s,sum,ans;
	n=4;
	N=n;
	s=0;
	for(i=0;i<n;i++)
	{
		s+=arr[i];
	}
	sum=s;
	//printf("%d/n",s);
	subset_sum(arr,sum,n);
	ans=min_subset_sum_diff(arr,s,N);
	printf("%d",ans);
}

