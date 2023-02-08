#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

void getbin(int* arr,int x,int counter)
{
	while(counter>-1)
	{
		arr[counter--]=x%2;
		x=x/2;
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	int sqr=pow(2,n);
	int* wt=calloc(n,sizeof(int));
	for(int i=0;i<n;i++)
		scanf("%d",&wt[i]);
	int* val=calloc(n,sizeof(int));
	for(int i=0;i<n;i++)
		scanf("%d",&val[i]);
	int cap;
	scanf("%d",&cap);
	int maxval=0;
	int weight=0;
	int value=0;
	int pos=-1;
	int** bit_vector=calloc(sqr,sizeof(int*));
	for(int i=0;i<sqr;i++)
	{
		bit_vector[i]=calloc(n,sizeof(int));
	}
	for(int i=0;i<sqr;i++)
	{
		getbin(bit_vector[i],i,n-1);
	}
	for(int i=0;i<sqr;i++)
	{
		weight=0;
		value=0;
		for(int j=0;j<n;j++)
		{
			printf("%d ",bit_vector[i][j]);
			if(bit_vector[i][j])
			{
				weight+=wt[j];
				value+=val[j];
			}
		}
		printf("\n");
		printf("weight=%d, value=%d",weight,value);
		if(value>maxval && weight<=cap)
		{
			pos=i;
			maxval=value;
		}
		printf("\n");
	}
	if(pos==-1)
		printf("No possibility\n");
	else
	{
		printf("Max value=%d\n",maxval);
		printf("Chosen items\n");
		for(int i=0;i<n;i++)
			printf("%d ",bit_vector[pos][i]); 
	}
	printf("\n");
	return 0;
}
