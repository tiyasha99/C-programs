#include <stdio.h>
#include <string.h>
int t[100][100];
int lcsubstring(char a[50],char b[50],int m,int n)
{
	int i,j,max;
	for(i=0;i<(m+1);i++)
		for(j=0;j<(n+1);j++)
		{
			if(i==0 || j==0)
				t[i][j]=0;
			else if(a[i-1]==b[j-1])
					t[i][j]=1+t[i-1][j-1];
			else
				t[i][j]=0;
		}
		max=-1;
	for(i=0;i<(m+1);i++)
		{
			printf("\n");
			for(j=0;j<(n+1);j++)
			{
				if(t[i][j]>max)
					max=t[i][j];
			}
		}
	return max;
}
int main()
{
	char a[50]="abcde";
	char b[50]="abfce";
	int m,n,ans;
	m=strlen(a);
	n=strlen(b);
	ans=lcsubstring(a,b,m,n);
	printf("%d",ans);
}

