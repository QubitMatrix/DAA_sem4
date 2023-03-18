#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct myarr
{
	int val;
	int pos;
};
typedef struct myarr myarr;
myarr* distribution_count_sort(int* arr,int n)
{
	int ind,l,u;
	l=INT_MAX;
	u=0;
	myarr* S=calloc(n,sizeof(myarr));
	for(int i=0;i<n;i++)//find min and max
	{
		if(arr[i]<l)
			l=arr[i];
		if(arr[i]>u)
			u=arr[i];
	}
	int* count=calloc(u-l+1,sizeof(int));
	for(int i=0;i<n;i++)//fill count table
	{
		ind=arr[i]-l;
		count[ind]+=1;
	}
	for(int i=1;i<u-l+1;i++)//get cumulative count
	{
		count[i]=count[i]+count[i-1];
	}
	for(int i=n-1;i>-1;i--)
	{
		ind=arr[i]-l;
		S[count[ind]-1].val=arr[i];
		S[count[ind]-1].pos=i;
		count[ind]--;
	}
	free(count);
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
	myarr* res=distribution_count_sort(arr,n);
	for(int i=0;i<n;i++)
	{
		printf("(%d,%d), ",res[i].val,res[i].pos);
	}
	printf("\n");
	free(arr);
	free(res);
	return 0;
}

