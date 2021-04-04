#include <stdio.h>
int t[100][100]={0};
void magic_square(int n)
{
	int i,j,k,num;
	k=n*n;
	i=n/2;
	j=n-1;
	num=1;
	t[i][j]=num++;
	while(num<=k)
	{
	
		i=i-1;
		j=j+1;
		
		
	if(t[i][j]!=0)
	{
		//printf("Num=%d",num);
		//printf("HI i=%d j=%d\n",i,j);
		i=i+1;
		j=j-2;
		//printf("Hey i=%d j=%d\n",i,j);
		t[i][j]=num++;	
		continue;
	}
if(i==-1 && j==n)
	{
			i=0;
			j=n-2;
	}
	else
	{
		
		if(i==-1)
			i=n-1;
		else if(j==n)
		{
				j=0;
		}
	
	}
	t[i][j]=num++;
	//k--;
	}
	for(i=0;i<n;i++)
	{
		printf("\n");
		for(j=0;j<n;j++)
		{
			printf("%d\t",t[i][j]);
		}
	}
}
int main()
{
	int n;
	printf("Enter a number:");
	scanf("%d",&n);
	magic_square(n);
}
