#include<stdio.h>
#include<stdlib.h>
#include<sys/times.h>
#include<math.h>
void swap(int* a,int* b)
{
	int t=*a;
	*a=*b;
	*b=t;
}
void quicksort(int* arr,int low,int high,int n)
{
	printf("%d %d\n",low,high);
	//sleep(3);
	if(low<high)// && high>=0 && low<n && low>=0 && high<n) 
	{
		int pivot=low;
		int i=low;
		int j=high+1;
		while(j>i)
		{
			for(int x=i+1;x<=high;x++)
			{
				if(arr[x]>arr[pivot])
				{
					i=x;
					break;
				}
			}
			for(int x=j-1;x>=low;x--)
			{
				if(arr[x]<arr[pivot])
				{
					j=x;
					break;
				}
			}
			printf("x%d",j);
			if(i==low)
				i=high;
			if(j==high+1)
				j=low;
			swap(&arr[i],&arr[j]);
		}
		swap(&arr[i],&arr[j]);
		swap(&arr[pivot],&arr[j]);
		printf("a%d %d\n",i,j);
		quicksort(arr,low,j-1,n);
		quicksort(arr,j+1,high,n);
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	int* arr=calloc(n,sizeof(int));
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	quicksort(arr,0,n-1,n);
	for(int i=0;i<n;i++)
		printf("%d ",arr[i]);
	return 0;
}
