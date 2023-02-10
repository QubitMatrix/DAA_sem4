#include<stdio.h>
#include<stdlib.h>

void insertionsort(int* arr,int n,int pos)
{ 
	int j,key;
	if(pos!=0)
	{
		insertionsort(arr,n,pos-1);
		j=pos-1;
		key=arr[pos];
		while(j>-1 && key<arr[j])
		{
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=key;
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	int* arr=calloc(n,sizeof(int));
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	insertionsort(arr,n,n-1);
	for(int i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");
	free(arr);
	return 0;
}
