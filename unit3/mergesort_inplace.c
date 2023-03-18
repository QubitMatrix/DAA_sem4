#include<stdio.h>
#include<stdlib.h>

void merge(int* arr,int low,int mid,int high)
{
	int i=low;
	int j=mid+1;
	int key;
	while(i<=mid)
	{
		if(arr[i]<=arr[j])
			i+=1;
		else
		{
			key=arr[j];
			for(int y=j;y>i;y--)
			{
				arr[y]=arr[y-1];
			}
			arr[i]=key;
			i+=1;
			j+=1;
			mid+=1;
		}
	}
}
void mergesort(int* arr,int low, int high)
{
	int mid;
	if(low<high)
	{
		mid=(low+high)/2;
		mergesort(arr,low,mid);
		mergesort(arr,mid+1,high);
		merge(arr,low,mid,high);
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	int* arr=calloc(n,sizeof(int));
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	mergesort(arr,0,n-1);
	for(int i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");
	free(arr);
	return 0;
}
