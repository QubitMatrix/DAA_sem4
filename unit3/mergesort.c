#include<stdio.h>
#include<stdlib.h>

void merge(int* arr,int low,int mid,int high)
{
	int i=low;
	int j=mid+1;
	int k=low;
	int* t=calloc(high+1,sizeof(int));
	while(i<=mid && j<=high)
	{
		if(arr[i]<=arr[j])
		{
			t[k++]=arr[i++];
		}
		else
		{
			t[k++]=arr[j++];
		}
	}
	while(i<=mid)
	{
		t[k++]=arr[i++];
	}
	while(j<=high)
	{
		t[k++]=arr[j++];
	}
	for(int i=low;i<=high;i++)
	{
		arr[i]=t[i];
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
