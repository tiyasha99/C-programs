#include <stdio.h>
#include <string.h>
int t[100][100];
int lcs(char x[],char y[20],int n,int m)
{
	int i,j;
	for(i=0;i<(n+1);i++)
	   for(j=0;j<(m+1);j++)
	   {
	   	 if(i==0 || j==0)
	   	 	t[i][j]=0;
	   	 else if(x[i-1]==y[j-1])
	   	 	t[i][j]=1+t[i-1][j-1];
	   	 else
	   	 	t[i][j]=max(t[i-1][j],t[i][j-1]);
	   }
	return t[n][m];
	
}
int max(int a ,int b)
	{
		return (a>b?a:b);
	}
void plcs(char a[50],char b[50],int m,int n)
{
	int i,j,k;
	char c[50];
	i=m;
	j=n;
	k=0;
	//printf("lul i=%d j=%d k=%d\n",i,j,k);
	while(i>0 || j>0)
	{
		if(a[i-1]==b[j-1])
			{
				//printf("i=%d j=%d k=%d\n",i,j,k);
				c[k]=a[i-1];
				i--;
				j--;
				
				//printf("%c",c[k]);
				k++;
				
			}
			
		else
		{
			if(t[i-1][j]>t[i][j-1])
				i--;
			else
				j--;
		}
	}
	//c[k++]='\0';
	//printf("\n%s\n",c);
	strrev(c);
	printf("\n%s\n",c);
}
int main()
{
	//int t[100][100];
	char x[6]={"abcdgh"};
	char y[7]={"abdefhr"};
	int m,n,ans;
	n=strlen(x);
	m=strlen(y);
	ans=lcs(x,y,n,m);
	printf("%d",ans);
	plcs(x,y,m,n);
}
