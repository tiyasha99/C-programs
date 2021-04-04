#include <stdio.h>
int adjacency[100][100]={0};
int visited[100]={0};
int stack[100];
int top=-1;
int n;
int a[100];
int N;
void addedge(int a,int b)
{
	adjacency[a][b]++;
}
void push(int item)
{
 if (top == 99)
        printf("Stack overflow ");
    else
        stack[++top] = item;
}
int pop()
{
	int k;
    if (top == -1)
        return (0);
    else
    {
        k = stack[top--];
        return (k);
    }
	
	
}
void dfs()
{
	int i,j,k;
	push(1);
	visited[1]=1;
	 k = pop();
    if (k != 0)
        printf(" %d ", k);
	while(k!=0)
	{
		for(i=1;i<=n;i++)
		{
			
			//j=pop();
			//printf("\n%d",j);
			if(adjacency[k][i]==0 && visited[i]==0)
			{
				visited[i]=1;
				
				push(i);
			}
		}
		k = pop();
        if (k != 0)
            printf(" %d ", k);
		
	}
	for (i = 1; i <= n; i++)
        if (visited[i] == 0)
            dfs(i, n);
	
}
int main()
{
	int a,b,c;
	printf("Enter the number of vertices:");
	scanf("%d",&n);
	N=n;
	do
	{
		printf("\nEnter 2 jobs at a time where the first job must be completed before the second job:");
		scanf("%d",&a);
		scanf("%d",&b);
		while((a>n && b>n)|| (a<0 || b<0))
		{
			
				printf("Please enter a valid vertex!\n Try again!");
				scanf("%d",&a);
				scanf("%d",&b);
			
			
			
			
		}
		addedge(a,b);
		printf("Keep Adding Edges?Press 1 for yes and 0 for no:");
		scanf("%d",&c);
	}while(c!=0);
	dfs();
	
}
