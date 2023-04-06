#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	int n,src,des;
	printf("Enter the number of vertices\n");
	scanf("%d",&n);
	int** mat=calloc(n,sizeof(int*));
	int** path=calloc(n,sizeof(int*));
	for(int i=0;i<n;i++)
	{
		mat[i]=calloc(n,sizeof(int));
		path[i]=calloc(n,sizeof(int));
	}
	printf("Enter the adjacency matrix\n");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d",&mat[i][j]);
		}
	}
	printf("R0\n");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%d ",mat[i][j]);
			if(mat[i][j] || i==j)
				path[i][j]=i;
		}
		printf("\n");
	}
    for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%d ",path[i][j]);
		}
		printf("\n");
	}

	for(int k=0;k<n;k++)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(mat[i][j]==0 && (mat[i][k] & mat[k][j])==1)
					path[i][j]=k;
				mat[i][j]=mat[i][j] | (mat[i][k] & mat[k][j]);
			}
		}
		printf("R%d\n",k+1);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				printf("%d ",mat[i][j]);
			}
			printf("\n");
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				printf("%d ",path[i][j]);
			}
			printf("\n");
		}
	}
	printf("Enter source and destination to get path\n");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(mat[i][j]==0 && i!=j)
				printf("Path doesnt exist between %d and %d\n",i,j);
			else
			{
				src=i;
				des=j;
				printf("Path(%d,%d)=%d ",src,des,des);
				while(src!=des)
				{
					printf("%d ",path[src][des]);
					des=path[src][des];

				}
				printf("\n");
			}
		}
	}
	return 0;
}
