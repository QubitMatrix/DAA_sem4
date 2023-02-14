#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void dfs(int** graph,int* visited,int* deadendorder,int n,int src,int* vorder,int* top,int* instack)
{
	(*vorder)++;
	visited[src]=*vorder;
	instack[src]=1;
	for(int i=0;i<n;i++)
	{
		if(graph[src][i]==1 && visited[i]==0)
			dfs(graph,visited,deadendorder,n,i,vorder,top,instack);
		else if(graph[src][i]==1 && visited[i]!=0 && instack[i]==1)
		{
			printf("DAG Error, topological sort cannot be performed\n");
			exit(1);
		}

	}
	instack[src]=0;
	deadendorder[(*top)++]=src;
}
void DFS(int** graph,int* visited,int* deadendorder,int n,int* instack)
{
	int vorder=0;
	int top=0;
	for(int i=0;i<n;i++)
	{
		if(visited[i]==0)
			dfs(graph,visited,deadendorder,n,i,&vorder,&top,instack);
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	int** graph=calloc(n,sizeof(int*));
	for(int i=0;i<n;i++)
	{
		graph[i]=calloc(n,sizeof(int));
	}
	int s,e;
	scanf("%d %d",&s,&e);
	while(s!=-1 && e!=-1)
	{
		graph[s][e]=1;
		scanf("%d %d",&s,&e);
	}
	int* visited=calloc(n,sizeof(int));
	int* deadendorder=calloc(n,sizeof(int));
	int* instack=calloc(n,sizeof(int));
	DFS(graph,visited,deadendorder,n,instack);
	printf("Order of visiting:\n");
	for(int i=0;i<n;i++)
	{
		printf("%d->%d\n",i,visited[i]);
	}
	printf("Dead end order:\n");
	for(int i=0;i<n;i++)
	{
		printf("%d\n",deadendorder[i]);
	}
	printf("Sorted:\n");
	for(int i=n-1;i>=0;i--)//stack like accessing
	{
		printf("%d ",deadendorder[i]);
	}
	printf("\n");
	return 0;
}
