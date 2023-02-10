#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"permutation_h.h"
#include<limits.h>
int main()
{
	int n,pos;
	pos=-1;
	int cost=0;
	int mincost=INT_MAX;
	int count=0;
	int src,des,dis;
	scanf("%d",&n);
	int** mat=calloc(n,sizeof(int*));
	for(int i=0;i<n;i++)
	{
		mat[i]=calloc(n,sizeof(int));
	}
	while(1)
	{
		scanf("%d %d %d",&src,&des,&dis);
		if(src==-1 && des==-1)
			break;
		mat[src][des]=dis;
	}
	printf("Graph(matrix representation)\n");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%d ",mat[i][j]);
		}
		printf("\n");
	}
	int* arr=calloc(n-1,sizeof(int));
	for(int i=1;i<n;i++)
		arr[i-1]=i;
	int fact=factorial(n-1);
	int** per=calloc(fact,sizeof(int*));
	for(int i=0;i<fact;i++)
		per[i]=calloc(n-1,sizeof(int));
	permutations(arr,n-1,0,per,&count);
	printf("Permutations of intermediate cities\n");
	for(int i=0;i<fact;i++)
	{
		for(int j=0;j<n-1;j++)
		{
			printf("%d ",per[i][j]);
		}
		printf("\n");
	}
	for(int i=0;i<fact;i++)
	{
		for(int j=0;j<n-2;j++)
		{
			cost+=mat[per[i][j]][per[i][j+1]];
		}
		cost+=mat[0][per[i][0]]+mat[per[i][n-2]][0];
		printf("cost:%d\ntour:\n0,",cost);
		for(int j=0;j<n-1;j++)
			printf("%d,",per[i][j]);
		printf("0\n");
		if(cost<mincost)
		{
			pos=i;
			mincost=cost;
		}	
		cost=0;
	}
	printf("Mincost=%d\nTour:0,",mincost);
	for(int i=0;i<n-1;i++)
	{
		printf("%d,",per[pos][i]);
	}
	printf("0\n");
	return 0;
}
