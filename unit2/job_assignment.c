#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include"permutation_h.h"

int main()
{
	int n;
	int pos=-1;
	int cost=0;
	int mincost=INT_MAX;
	int count=0;
	scanf("%d",&n);
	int** mat=calloc(n,sizeof(int*));
	for(int i=0;i<n;i++)
		mat[i]=calloc(n,sizeof(int));
	for(int i=0;i<n;i++)//person
	{
		for(int j=0;j<n;j++)//jobs
		{
			scanf("%d",&mat[i][j]);
		}
	}
	int* arr=calloc(n,sizeof(int));
	for(int i=0;i<n;i++)
	{
		arr[i]=i;
	}
	int fact=factorial(n);
	printf("Factorial%d\n",fact);
	int** per=calloc(fact,sizeof(int*));
	for(int i=0;i<fact;i++)
	{
		per[i]=calloc(n,sizeof(int));
	}
	permutations(arr,n,0,per,&count);
	for(int i=0;i<fact;i++)//jobs
	{
		for(int j=0;j<n;j++)//persons
		{
			cost+=mat[j][per[i][j]];
			printf("P:%d J:%d\n",j,per[i][j]);
		}
		printf("Cost:%d\n",cost);
		if(cost<mincost)
		{
			pos=i;
			mincost=cost;
		}
		cost=0;
	}
	printf("Mincost:%d\n",mincost);
	printf("Assignment:\n");
	for(int i=0;i<n;i++)
		printf("%d ",per[pos][i]);
	printf("\n");
	return 0;
}
