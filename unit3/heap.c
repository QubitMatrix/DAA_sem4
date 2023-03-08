#include<stdio.h>
#include<stdlib.h>

void heapify(int* arr,int n,int i)
{
	int k,key,j,heap;
	k=i;
	key=arr[k];
	heap=0;
	while(2*k+1<n && heap==0)
	{
		j=2*k+1;
		if(j<n-1)
		{
			if(arr[j]>arr[j+1])
				j=j+1;
		}
		if(key>arr[j])
		{
			arr[k]=arr[j];
			k=j;
		}
		else
			heap=1;
	}
	arr[k]=key;
}
void delete_root(int* arr,int n)
{
	arr[0]=arr[n-1];
	heapify(arr,n-1,0);
}

void heap_sort(int* t,int* arr,int n)
{
	int p=n/2-1;
	for(int i=p;i>-1;i--)
	{
		heapify(arr,n,i);
	}
	int pos=0;
	while(n!=0)
	{
		t[pos++]=arr[0];
		delete_root(arr,n);
		n=n-1;
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	int arr[n];
	int t[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	heap_sort(t,arr,n);
	printf("Sorted:\n");
	for(int i=0;i<n;i++)
		printf("%d ",t[i]);
	printf("\n");
	return 0;
}
