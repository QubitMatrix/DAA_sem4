#include<stdio.h>
#include<stdlib.h>
void permutations(int* arr,int n,int fixed,int** ans,int *count)
{
	int t;
	if(fixed==n-1)
	{
		for(int i=0;i<n;i++)
		{
			printf("%d",arr[i]);
			ans[*count][i]=arr[i];
		}
		(*count)++;
		//ans[(*count)++]=arr;
		printf("\n");
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

