#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define max(a,b) a>b?a:b
struct table
{
	int item;
	int weight;
	int profit;
};
typedef struct table table;
int main()
{
	int n,cap;
	printf("Enter the capacity\n");
	scanf("%d",&cap);
	printf("Enter the number of items\n");
	scanf("%d",&n);
	int* sol_vec=calloc(n,sizeof(int));
	table* det=calloc(n,sizeof(table));
	int** mat=calloc(n+1,sizeof(int*));
	for(int i=0;i<n+1;i++)
		mat[i]=calloc(cap+1,sizeof(int));
	printf("Enter the values(item weight profit)\n");
	for(int i=0;i<n;i++)
	{
		scanf("%d %d %d",&det[i].item,&det[i].weight,&det[i].profit);
	}
	for(int i=1;i<n+1;i++)
	{
		for(int j=1;j<cap+1;j++)
		{
			if(det[i-1].weight<=j)
			{
				mat[i][j]=max(mat[i-1][j],det[i-1].profit+mat[i-1][j-det[i-1].weight]);
			}
			else
			{
				mat[i][j]=mat[i-1][j];
			}
		}
	}
	printf("Tabulation table\n");
	for(int i=1;i<n+1;i++)
	{
		for(int j=1;j<cap+1;j++)
		{
			printf("%d ",mat[i][j]);
		}
		printf("\n");
	}
	int i=n;
	int j=cap;
	int k=0;
	while(i!=0)
	{
		if(mat[i][j]==mat[i-1][j])
			i--;
		else
		{
			sol_vec[i-1]=1;
			i--;
			j=j-det[i].weight;
		}
	}
	printf("Solution vector: ");
	for(int k=0;k<n;k++)
	{
		printf("%d ",sol_vec[k]);
	}
	printf("\n");
	return 0;
}
