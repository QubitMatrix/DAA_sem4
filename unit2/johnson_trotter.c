#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int factorial(int n)
{
	if(n==1)
		return 1;
	return(n*factorial(n-1));
}
void jt_permutation(int* arr,int n,int* dir,int** ans)
{
	int mobile_val=0;
	int mobile_pos=0;
	int prev,t,swap_pos;
	int count=0;
	for(int i=0;i<n;i++)
		ans[0][i]=arr[i];
	count++;
	while(1)
	{
		mobile_val=-1;
		for(int i=0;i<n;i++)
		{
			if(dir[arr[i]]==1 && i+1<n && arr[i+1]<arr[i] && arr[i]>mobile_val)
			{
				mobile_val=arr[i];
				mobile_pos=i;
			}
			if(dir[arr[i]]==0 && i-1>-1 && arr[i-1]<arr[i] && arr[i]>mobile_val)
			{
				mobile_val=arr[i];
				mobile_pos=i;
			}
		}
		if(mobile_val==-1)
			break;
		printf("Mobile:%d\n",mobile_val);
		t=arr[mobile_pos];
		swap_pos=dir[mobile_val]==1?mobile_pos+1:mobile_pos-1;
		arr[mobile_pos]=arr[swap_pos];
		arr[swap_pos]=t;
		for(int i=0;i<n;i++)
		{
			printf("%d ",arr[i]);
			ans[count][i]=arr[i];
			if(arr[i]>mobile_val)
				dir[arr[i]]=1-dir[arr[i]];
		}
		printf("\n");
		count++;
	}
}


int main()
{
	int n;
	scanf("%d",&n);
	int* arr=calloc(n,sizeof(int));
	int* dir=calloc(n,sizeof(int));
	for(int i=0;i<n;i++)
	{
		arr[i]=i;
		dir[i]=0;
	}
	int fact=factorial(n);
	int** ans=calloc(fact,sizeof(int*));
	for(int i=0;i<fact;i++)
		ans[i]=calloc(n,sizeof(int));
	jt_permutation(arr,n,dir,ans);
	printf("Permutations:\n");
	for(int i=0;i<fact;i++)
	{
		for(int j=0;j<n;j++)
			printf("%d",ans[i][j]);
		printf("\n");
	}
	return 0;
}

