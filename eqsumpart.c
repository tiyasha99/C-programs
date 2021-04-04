#include <stdio.h>
#include <stdbool.h>
bool t[100][100];
bool equal_sum_partition(int arr[],int n)
{
	int i,j,sum=0,s;
	for(i=0;i<n;i++)
		{
			sum+=arr[i];
		}
	//printf("%d",sum);
	if((sum%2)!=0)
		return false;
	else
	{
		s=sum/2;
		//printf("%d",s);
		for(i=0;i<(n+1);i++)
			for(j=0;j<(s+1);j++)
			{
				if(i==0)
					t[i][j]=false;
				if(j==0)
					t[i][j]==true;
				else
				{
					if(arr[i-1]<=j)
						t[i][j]=t[i][j-arr[i-1]] || t[i-1][j];
					else
						t[i][j]=t[i-1][j];
				}
			}
		return t[n][s];
	}
	
}
int main()
{
	int n=4;
	bool ans;
	int arr[4]={1,5,5,12};
	ans=equal_sum_partition(arr,n);
	//printf(ans?"true":"false",stdout);
	//printf("%d",ans);
	//printf("%s", x ? "true" : "false");
	printf(ans ? "true" : "false");
}
