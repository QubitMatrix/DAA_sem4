#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void binary_gray_code(int count,int n,int** ans)
{
	int counter1;
	for(int counter=0;counter<count;counter++)
	{
		counter1=counter ^ (counter>>1);
		printf("%d\n",counter1);
		for(int i=0;i<n;i++)
		{
			if(counter1 & (1<<i))
			{
				ans[counter1][i]=1;
			}
		}
	}
}
void squashed_or_subset(int** ans,int choice,int count,int n,int* set)
{
	if(choice==1)//(a,b,c)
	{
		printf("Not squashed\n");
		for(int i=0;i<count;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(ans[i][j])
					printf("%d ",set[n-1-j]);
			}
			if(i==0)
				printf("phi");
			printf("\n");
		}
	}
	else//(c,b,a)-squashed
	{
		printf("Squashed\n");
		for(int i=0;i<count;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(ans[i][j])
					printf("%d ",set[j]);
			}
			if(i==0)
				printf("phi");
			printf("\n");
		}
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	int* set=calloc(n,sizeof(int));
	for(int i=0;i<n;i++)
		scanf("%d",&set[i]);
	int count=pow(2,n);
	int** ans=calloc(count,sizeof(int*));
	for(int i=0;i<count;i++)
	{
		ans[i]=calloc(n,sizeof(int));
	}
	binary_gray_code(count,n,ans);
	int choice;
	scanf("%d",&choice);
	squashed_or_subset(ans,choice,count,n,set);
	return 0;
}
