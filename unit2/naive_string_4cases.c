#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int lr_lr(char* text,char* pattern)
{
	int cmp=0;
	int m=strlen(pattern);
	int n=strlen(text);
	int j=0;
	for(int i=0;i<n-m+1;i++)
	{
		j=0;
		cmp++;
		while(j<m && text[i+j]==pattern[j])
		{
			j++;
			cmp++;
		}
		if(j==m)
		{
			printf("Found\n");
			return cmp-1;
		}
		//printf("%d %d\n",i,cmp);
	}
	printf("Not found\n");
	return cmp;
}
int lr_rl(char* text,char* pattern)//window left to right and matching right to left
{
	int cmp=0;
	int m=strlen(pattern);
	int n=strlen(text);
	int j=0;
	for(int i=0;i<n-m+1;i++)
	{
		j=m-1;
		cmp++;
		while(j>-1 && text[i+j]==pattern[j])
		{
			j--;
			cmp++;
		}
		if(j==-1)
		{
			printf("Found\n");
			return cmp-1;
		}
	}
	printf("Not found\n");
	return cmp;
}
int rl_lr(char* text,char* pattern)
{
	int cmp=0;
	int m=strlen(pattern);
	int n=strlen(text);
	int j=0;
	for(int i=n-m;i>-1;i--)
	{
		j=0;
		cmp++;
		while(j<m && text[i+j]==pattern[j])
		{
			j++;
			cmp++;
		}
		if(j==m)
		{
			printf("Found\n");
			return cmp-1;
		}
		//printf("%d %d\n",i,cmp);
	}
	printf("Not found\n");
	return cmp;
}
int rl_rl(char* text,char* pattern)
{
	int cmp=0;
	int m=strlen(pattern);
	int n=strlen(text);
	int j=0;
	for(int i=n-m;i>-1;i--)
	{
		j=m-1;
		cmp++;
		while(j>-1 && text[i+j]==pattern[j])
		{
			j--;
			cmp++;
		}
		if(j==-1)
		{
			printf("Found\n");
			return cmp-1;
		}
	}
	printf("Not found\n");
	return cmp;
}
int main()
{
	char text[1000];
	char pattern[100];
	int cmp;
	scanf("%s",text);
	scanf("%s",pattern);
	cmp=lr_lr(text,pattern);
	printf("(lr_lr):comparisons=%d\n",cmp);
	cmp=lr_rl(text,pattern);
	printf("(lr_rl):comparisons=%d\n",cmp);
	cmp=rl_lr(text,pattern);
	printf("(rl_lr):comparisons=%d\n",cmp);
	cmp=rl_rl(text,pattern);
	printf("(rl_rl):comparisons=%d\n",cmp);
	return 0;
}
