#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n;
	scanf("%d",&n);
	int* arr=calloc(sizeof(int),n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	int minpos=0;
	for(int i=0;i<n-1;i++)
	{
		minpos=i;
		for(int j=i+1;j<n;j++)
		{
			if(arr[minpos]>arr[j])
				minpos=j;
		}
		int t=arr[minpos];
		arr[minpos]=arr[i];
		arr[i]=arr[minpos];
	}
	for(int i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	return 0;
}
