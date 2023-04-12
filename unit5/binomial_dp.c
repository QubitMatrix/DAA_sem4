#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define min(a,b) a>b?b:a
void freeall(int** mat,int n)//mat is a copy here main will still hold address
{
	for(int i=0;i<n+1;i++)
		free(mat[i]);
	free(mat);
}
int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	int** mat=calloc(n+1,sizeof(int*));
	for(int i=0;i<n+1;i++)
	{
		mat[i]=calloc(k+1,sizeof(int));
		mat[i][0]=1;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=(min(i,k));j++)//without () for min ->infinite loop
		{
			mat[i][j]=mat[i-1][j]+mat[i-1][j-1];
		}
	}
	printf("Pascal Triangle\n");
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=k;j++)
		{
			printf("%d ",mat[i][j]);
		}
		printf("\n");
	}
	printf("%dC%d=%d\n",n,k,mat[n][k]);
	freeall(mat,n); //all pointers are freed but the mat still has address in main(dangling pointer)
	//free(mat);
	mat=NULL;
	return 0;
}
