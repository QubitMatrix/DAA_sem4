#include<stdio.h>
#include<stdlib.h>

int crude(int* arr,int n)
{
	int cmp=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			cmp+=1;
			if(arr[j]>arr[j+1])
			{
				int t=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=t;
			}
		}
	}
	return cmp;
}
int optimised(int* arr,int n)
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
int main()
{
	int n;
	scanf("%d",&n);
	int arr1[n];
	int arr2[n];
	int cmp;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr1[i]);
		arr2[i]=arr1[i];
	}
	cmp=crude(arr1,n);
	printf("(crude)Comparisons:%d\n",cmp);
	for(int i=0;i<n;i++)
	{
		printf("%d ",arr1[i]);
	}
	cmp=optimised(arr2,n);
	printf("\n(optimsed)Comparisons:%d\n",cmp);
	for(int i=0;i<n;i++)
	{
		printf("%d ",arr2[i]);
	}
	printf("\n");
	return 0;
}

