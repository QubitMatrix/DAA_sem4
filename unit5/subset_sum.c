#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct newstruct
{
    int size;
    int arr[100];
};
typedef struct newstruct newstruct;

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
void subset_sum(int size,int sum,int* set,int pos,int sum_prev,int* ans,int* count,newstruct* new_arr)
{
	if(sum_prev==sum)
	{
		int j=0;
		for(int i=0;i<size;i++)
		{
		    if(ans[i])
		    {
			new_arr[*count].arr[j]=set[i];
			j++;
		    }
		}
		new_arr[*count].size=j;
		(*count)++;
	}
	else if(pos<size)
	{
		if(sum_prev+set[pos]<=sum) //include
		{
			ans[pos]=1;
			subset_sum(size,sum,set,pos+1,sum_prev+set[pos],ans,count,new_arr);
			ans[pos]=0;
		}
		if(sum_prev+(remaining_sum(pos,size,set))>=sum) //exclude
			subset_sum(size,sum,set,pos+1,sum_prev,ans,count,new_arr);
	}
}
int main()
{
	int size,sum;
	scanf("%d",&size);
	int* ans=calloc(size,sizeof(int));
	int* set=calloc(size,sizeof(int));
    	newstruct* new_arr=calloc(100,sizeof(newstruct));
	for(int i=0;i<size;i++)
		scanf("%d",&set[i]);
    	scanf("%d",&sum);
	qsort(set,size,4,cmp);
	int count=0;
    	subset_sum(size,sum,set,0,0,ans,&count,new_arr);
    	printf("%d\n",count);
    	for(int i=0;i<count;i++)
    	{
		for(int j=0;j<new_arr[i].size;j++)
		{
		    printf("%d ",new_arr[i].arr[j]);
		}
		printf("\n");
    	}
	free(ans);
	free(set);
    	free(new_arr);
	return 0;
}
