#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int place(int queen,int col,int* vector)
{
	for(int i=0;i<queen;i++)
	{
		if(col==vector[i] || ((abs(queen-i))==1 && abs(col-vector[i])==1))
			return 0;
	}
	return 1;
}
void nqueen(int queen,int total,int* vector)
{
	if(queen>=total)
	{
		for(int i=0;i<total;i++)
			printf("%d ",vector[i]+1);
		printf("\n");
	}
	else
	{
		for(int c=0;c<total;c++)
		{
			if(place(queen,c,vector))
			{
				vector[queen]=c;
				nqueen(queen+1,total,vector);
				vector[queen]=-1;
			}

		}
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	int* vector=calloc(n,sizeof(int));
	for(int i=0;i<n;i++)
		vector[i]=-1;
	nqueen(0,n,vector);
	free(vector);
	return 0;
}
