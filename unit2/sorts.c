#include<stdio.h>
int bubblesort(int* arr,int n)
{
	int cmp=0;
	int swp=0;
	for(int i=0;i<n;i++)
	{
		swp=0;
		for(int j=0;j<n-i-1;j++)
		{
			cmp+=1;
			if(arr[j]>arr[j+1])
			{
				swp+=1;
				int t=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=t;
			}
		}
		if(!swp)
			break;
	}
	return cmp;
}
void insertionsort(int* arr,int n)
{
	int j=0;
	int key=0;
	for(int i=1;i<n-1;i++)
	{
		j=i-1;
		key=arr[i];
		while(j>-1 && key<arr[j])
		{
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=key;
	}
}
void selectionsort(int*arr,int n)
{
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
		arr[i]=t;
	}
}
