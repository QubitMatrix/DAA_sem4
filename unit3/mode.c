#include<stdio.h>
#include<stdlib.h>
int mode(int* arr,int n)
{
	int count=1;
	int mode=0;
	int max=0;
	int value=arr[0];
	for(int i=1;i<n;i++)
	{
		if(arr[i]==value)
			count+=1;
		else
		{
			if(count>max)
			{
				max=count;
				mode=value;
			}
			value=arr[i];
			count=1;
		}
	}
	return mode;
}

int cmp(const void* a,const void* b)
{
	return(*(int*)a-*(int*)b);
}
int main()
{
	int n;
	scanf("%d",&n);
	int* arr=calloc(n,sizeof(int));
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	qsort(arr,n,sizeof(int),cmp);//presort
	int mode1=mode(arr,n);
	printf("%d\n",mode1);
	return 0;
}
