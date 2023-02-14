#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int check_queue(int src,int* queue,int size)
{
	for(int i=0;i<size;i++)
	{
		if(queue[i]==src)
			return 1;
	}
	return 0;
}
int count_indegree(int** graph,int n,int node)
{
	int sum=0;
	for(int i=0;i<n;i++)
	{
		sum+=graph[i][node];
	}
	return sum;
}
void remove_outgoing(int** graph,int n,int node)
{
	for(int i=0;i<n;i++)
	{
		graph[node][i]=0;
	}
}
int check_cycle(int** graph,int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(graph[i][j]==1)
				return 1;
		}
	}
	return 0;
}
void sourceremoval(int** graph,int n,int* queue)
{
	int indegree,checkq;
	int i=0;
	int rear=0;
	while(i<n)
	{
		checkq=check_queue(i,queue,rear);
		if(checkq)
		{
			i++;
			continue;
		}
		indegree=count_indegree(graph,n,i);
		if(indegree==0)
		{
			queue[rear++]=i;
			remove_outgoing(graph,n,i);
			i=-1;
		}
		i++;
	}
	int check=check_cycle(graph,n);
	if(check)
	{
		printf("DAG Error, cannot do topological sort\n");
		exit(1);
	}
	else
	{
		printf("Topological order:\n");
		for(int i=0;i<n;i++)
			printf("%d ",queue[i]);
	}
	printf("\n");
}
int main()
{
	int n,s,e;
	scanf("%d",&n);
	int* queue=calloc(n,sizeof(int));
	int** graph=calloc(n,sizeof(int*));
	for(int i=0;i<n;i++)
		graph[i]=calloc(n,sizeof(int));
	scanf("%d %d",&s,&e);
	while(s!=-1 && e!=-1)
	{
		graph[s][e]=1;
		scanf("%d %d",&s,&e);
	}
	sourceremoval(graph,n,queue);
	return 0;
}
