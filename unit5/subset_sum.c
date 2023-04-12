#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cmp(const void* a,const void* b)
{
	return *(int*)a-*(int*)b;
}
int remaining_sum(int pos,int size,int* set)
{
	int sum=0;
	for(int i=pos+1;i<size;i++)
		sum+=set[i];
	return sum;
}
void subset_sum(int size,int sum,int* set,int pos,int sum_prev,int* ans)
{
	if(sum_prev==sum)
	{
		for(int i=0;i<size;i++)
			if(ans[i])
				printf("%d ",set[i]);
		printf("\n");
	}
	else if(pos<size)
	{
		if(sum_prev+set[pos]<=sum) //include
		{
			ans[pos]=1;
			subset_sum(size,sum,set,pos+1,sum_prev+set[pos],ans);
			ans[pos]=0;
		}
		if(sum_prev+(remaining_sum(pos,size,set))>=sum) //exclude
			subset_sum(size,sum,set,pos+1,sum_prev,ans);
	}
}
int main()
{
	int size,sum;
	scanf("%d %d",&size,&sum);
	int* ans=calloc(size,sizeof(int));
	int* set=calloc(size,sizeof(int));
	for(int i=0;i<size;i++)
		scanf("%d",&set[i]);
	qsort(set,size,4,cmp);
	printf("Subsets:\n");
	subset_sum(size,sum,set,0,0,ans);
	free(ans);
	free(set);
	return 0;
}
