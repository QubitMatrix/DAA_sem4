#include<stdio.h>
#include<stdlib.h>
#define min(a,b)(a>b?b:a)
int find_min(int* arr,int start,int end)
{
	if(start==end)
		return arr[start];
	else
	{
		int mid=(start+end)/2;
		return min(find_min(arr,start,mid),find_min(arr,mid+1,end));
	}
}
int main()
{
	int n;
	int* arr=calloc(n,sizeof(int));
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	int minn=find_min(arr,0,n-1);
	printf("%d\n",minn);
	free(arr);
	return 0;
}
