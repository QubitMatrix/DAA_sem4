#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void freeall(int** graph,int** path,int n)
{
	for(int i=0;i<n;i++)
	{
		free(graph[i]);
		free(path[i]);
	}
	free(graph);
	free(path);
}
int main()
{
	int n,e,start,end,cost,src,des;
	printf("Enter the number of vertices and edges\n");
	scanf("%d %d",&n,&e);
	int** graph=calloc(n,sizeof(int*));
	int** path=calloc(n,sizeof(int*));
	for(int i=0;i<n;i++)
	{
		graph[i]=calloc(n,sizeof(int));
		path[i]=calloc(n,sizeof(int));
		for(int j=0;j<n;j++)
		{
			graph[i][j]=999999;
			path[i][j]=-1;
			if(i==j)
			{
				graph[i][j]=0;
				path[i][j]=i;
			}
		}
	}
	printf("Enter the edges(start end cost)\n");
	for(int i=0;i<e;i++)
	{
		scanf("%d %d %d",&start,&end,&cost);
		//printf("%d %d %d\n",start,end,cost);
		graph[start][end]=cost;
		path[start][end]=start;
	}
	for(int k=0;k<n;k++)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(graph[i][j]>graph[i][k]+graph[k][j])
				{
					graph[i][j]=graph[i][k]+graph[k][j];
					path[i][j]=k;
				}
			}
		}
	}
	printf("Distance matrix\n");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%d ",graph[i][j]);
		}
		printf("\n");
	}
	printf("Path matrix\n");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%d ",path[i][j]);
		}
		printf("\n");
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("Path(%d %d):",i,j);
			src=i;
			des=j;
			while(des!=src)
			{
				printf("%d ",des);
				des=path[src][des];
			}
			printf("%d\ncost=%d\n",src,graph[i][j]);
		}
	}
	freeall(graph,path,n);
	graph=NULL;
	path=NULL;
	return 0;
}
