#include<stdio.h>
#include<stdlib.h>
struct myarr
{
	int val;
	int pos;
};
typedef struct myarr myarr;
myarr* cmp_sort(int* arr,int n)
{
	int* count_min=calloc(n,sizeof(int));
	myarr* S=calloc(n,sizeof(myarr));
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(arr[j]<arr[i])
				count_min[i]++;
			else
				count_min[j]++;
		}
	}		
	for(int i=0;i<n;i++)
	{
		S[count_min[i]].val=arr[i];
		S[count_min[i]].pos=i;
	}
	return S;
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
	myarr* res=cmp_sort(arr,n);
	printf("After sorting\n");
	for(int i=0;i<n;i++)
		printf("(%d,%d),",res[i].val,res[i].pos);
	printf("\n");
	return 0;
}
