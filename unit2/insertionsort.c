#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n;
	int j=0;
	int key=0;
	scanf("%d",&n);
	int *arr=calloc(n,sizeof(int));
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
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
	for(int i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");
	return 0;
}
