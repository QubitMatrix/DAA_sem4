#include<stdio.h>
#include<stdlib.h>
void permutations(int* arr,int n,int fixed,int** ans,int *count)
{
	int t;
	if(fixed==n-1)
	{
		for(int i=0;i<n;i++)
		{
			ans[*count][i]=arr[i];
		}
		(*count)++;
	}
	else
	{
		for(int x=fixed;x<n;x++)
		{
			t=arr[fixed];
			arr[fixed]=arr[x];
			arr[x]=t;
			permutations(arr,n,fixed+1,ans,count);
			t=arr[fixed];
			arr[fixed]=arr[x];
			arr[x]=t;
		}
	}
}
int factorial(int n)
{
	if(n==1)
		return 1;
	return (n*factorial(n-1));
}

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
	free(arr);
	arr=NULL;
	for(int i=0;i<fact;i++)
	{
		for(int j=0;j<n;j++)
			printf("%d ",ans[i][j]);
		printf("\n");
		free(ans[i]);
		ans[i]=NULL;
	}
	free(ans);
	ans=NULL;	
	return 0;
}
