#include<stdio.h>
#include<stdlib.h>
#define max(a,b) (a>b?a:b)
int mode(int* arr,int n,int max_arr)
{
	int* dic=calloc(max_arr+1,sizeof(int));
	int mode=0;
	int maxval=0;
	for(int i=0;i<n;i++)
	{
		dic[arr[i]]+=1;
	}
	for(int i=0;i<n;i++)
	{
		if(dic[arr[i]]>maxval)
		{
			maxval=dic[arr[i]];
			mode=arr[i];
		}
	}
	return mode;
}

int main()
{
	int n;
	int max_arr=0;
	scanf("%d",&n);
	int* arr=calloc(n,sizeof(int));
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
		max_arr=max(max_arr,arr[i]);
	}
	int mode1=mode(arr,n,max_arr);
	printf("%d\n",mode1);
	return 0;
}
