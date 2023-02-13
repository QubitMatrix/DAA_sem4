#include<stdio.h>
#include<stdlib.h>
#include"permutation_h.h"
int main()
{
	int n;
	scanf("%d",&n);
	int* arr=calloc(n,sizeof(int));
	for(int i=0;i<n;i++)
		arr[i]=i+1;
	int fact=factorial(n);
	int** ans=calloc(fact,sizeof(int*));
	for(int i=0;i<fact;i++)
	{
		ans[i]=calloc(n,sizeof(int));
	}
	int count=0;
	permutations(arr,n,0,ans,&count);
	printf("Printing from client\n");
	for(int i=0;i<fact;i++)
	{
		for(int j=0;j<n;j++)
			printf("%d ",ans[i][j]);
		printf("\n");
	}
	free(arr);
	arr=NULL;
	for(int i=0;i<fact;i++)
	{
		free(ans[i]);
		ans[i]=NULL;
	}
	free(ans);
	ans=NULL;

	return 0;
}
