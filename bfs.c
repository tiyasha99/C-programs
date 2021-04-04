/*program for bfs */
#include<stdio.h>
#include<stdlib.h>
int adj[50][50],queue[50],vis[50];
void main()
{
        int i=0,j=0,k=0,e,v,r=0,front=0,rear=0;
        printf("\n Is the graph directed?1-yes,0-no: ");
        scanf("%d",&i);
        printf("\nEnter the no.of edges:");
        scanf("%d",&e);
        printf("\nEnter the no.of vertices:");
        scanf("%d",&v);

        if(i==1)
        {
                for(k=0;k<e;k++)
                {
                        printf("\n Enter the adjacent vertices of edges e[%d]:",k);
                        scanf("%d",&j);
                        scanf("%d",&r);
                        adj[j][r]=1;
                }
        }
        else
        {
                for(k=0;k<e;k++)
                {
                        printf("\n Enter the adjacent vertices of edges e[%d]:",k);
                        scanf("%d",&j);
                        scanf("%d",&r);
                        adj[j][r]=1;
                        adj[r][j]=1;
                }

        }
        printf("\n The adjacency matrix is: \n");
        for(j=0;j<v;j++)
        {
                for(r=0;r<v;r++)
                {
                        printf(" %d ",adj[j][r]);
                }
                printf("\n");
        }
        queue[++front]=0;
        rear=rear+1;
        for(j=0;j<v;j++)
        {
                vis[j]=0;
        }
        vis[0]=1;
        for(j=queue[front];j<v;j++)
        {
                for(r=0;r<v;r++)
                {
                        if(adj[j][r]==1)
                        {
                                if(vis[r]==0)
                                {
                                  queue[++rear]=r;
                                        vis[r]=1;

                                }
                        }
                }


        printf("%d",queue[front++]);
        }
}

