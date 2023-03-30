#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

void init_graph(int n;int* graph[n],int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			graph[i][j]=INT_MAX;
		}
	}
}
void init_singleSourceShortestPath(int n;int* graph[n],int n,int src,int* d,int* p)
{
	for(int i=0;i<n;i++)
	{
		d[i]=INT_MAX;
		p[i]=-1;
	}
	d[src]=0;
	p[src]=src;
}
void relax_edge(int n;int* graph[n],int n,int* d,int* p,int u,int v)
{
	if(d[v]>d[u]+graph[u][v])
	{
		d[v]=d[u]+graph[u][v];
		p[v]=u;
	}
	
}
int minimum(int* d,int* s,int n)
{
	int min=0;
	int minval=INT_MAX;
	for(int i=0;i<n;i++)
	{
		if(d[i]<minval && s[i]==0)
		{
			min=i;
			minval=d[i];
		}
	}
	return min;
}

void dijkstra(int n;int* graph[n],int n,int* d,int* p,int* s)
{

	int src=0;
	int u;
	init_singleSourceShortestPath(graph,n,src,d,p);
	for(int i=0;i<n-1;i++)
	{
		u=minimum(d,s,n);
		s[u]=1;//add into selected

		for(int v=0;v<n;v++)
		{
			if(graph[u][v]!=INT_MAX && s[v]==0)//neighbor and not in selected
				relax_edge(graph,n,d,p,u,v);
		}
	}
}
int main()
{
	int n,e,u,v,w;
	printf("Enter number of vertices and edges\n");
	scanf("%d %d",&n,&e);
	int* d=calloc(n,sizeof(int));
	int* p=calloc(n,sizeof(int));
	int* s=calloc(n,sizeof(int));
	int** graph=calloc(n,sizeof(int*));
	for(int i=0;i<n;i++)
	{
		graph[i]=calloc(n,sizeof(int));
	}
	init_graph(graph,n);
	printf("Enter the edges along with its weight(u v w)\n");
	for(int i=0;i<e;i++)
	{
		scanf("%d %d %d",&u,&v,&w);
		graph[u][v]=w;
	}
	dijkstra(graph,n,d,p,s);
	printf("Distances:\n");
	for(int i=0;i<n;i++)
	{
		printf("%d %d %d\n",i,d[i],p[i]);
	}
	for(int i=0;i<n;i++)
		free(graph[i]);
	free(graph);
	free(d);
	free(p);
	free(s);
	return 0;
}

