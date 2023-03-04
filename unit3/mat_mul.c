#include<stdio.h>
#include<stdlib.h>

int main()
{
	int r1,r2,c1,c2;
	scanf("%d %d %d %d",&r1,&c1,&r2,&c2);
	if(c1!=r2)
	{
		printf("Can't do it\n");
		exit(0);
	}
	int** arr1=calloc(r1,sizeof(int*));
	int** arr2=calloc(r2,sizeof(int*));
	for(int i=0;i<c1;i++)
		arr1[i]=calloc(c1,sizeof(int));
	for(int i=0;i<c2;i++)
		arr2[i]=calloc(c2,sizeof(int));
	for(int i=0;i<r1;i++)
	{
		for(int j=0;j<c1;j++)
		{
			scanf("%d",&arr1[i][j]);
		}
	}
	for(int i=0;i<r2;i++)
	{
		for(int j=0;j<c2;j++)
		{
			scanf("%d",&arr2[i][j]);
		}
	}
	int** ans=calloc(r1,sizeof(int*));
	for(int i=0;i<r1;i++)
	{
		ans[i]=calloc(c2,sizeof(int));
	}
	for(int i=0;i<r1;i++)
	{
		for(int j=0;j<c2;j++)
		{
			for(int k=0;k<c1;k++)
			{
				ans[i][j]=ans[i][j]+arr1[i][k]*arr2[k][j];
			}
		}
	}

	for(int i=0;i<r1;i++)
	{
		for(int j=0;j<c2;j++)
		{
			printf("%d ",ans[i][j]);
		}
		printf("\n");
	}
	for(int i=0;i<r1;i++)
	{
		free(arr1[i]);
		free(ans[i]);
	}
	for(int i=0;i<r2;i++)
	{
		free(arr2[i]);
	}
	free(arr1);
	free(arr2);
	free(ans);
	return 0;
}
