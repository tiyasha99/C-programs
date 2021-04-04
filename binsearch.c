#include <stdio.h>
#include <stdlib.h>
int binary(int a[],int n,int key)
{
	int low,high,mid,flag=0;
	low=0;
	high=n-1;
	printf("low=%d high=%d\n",low,high);
	while(low<=high)
	{
		mid=(low+high)/2;
		printf("mid=%d\n",mid);
		
		
		if(a[mid]<key)
			low=mid+1;
		else if(a[mid]==key)
		{
			flag=1;
			return 1;
		}
		else
			high=mid-1;
	}
	
}
int main()
{
	int n,ans;
	int a[]={1,2,3,5,8};
	n=sizeof(a)/sizeof(int);
	ans=binary(a,n,5);
	if(ans==1)
		printf("yes");
	else
		printf("no");
}
