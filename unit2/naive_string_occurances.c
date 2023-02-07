#include<stdio.h>
#include<string.h>

int overlap(char* text,char* pattern)
{
	int count=0;
	int j;
	int m=strlen(pattern);
	int n=strlen(text);
	for(int i=0;i<n-m+1;i++)
	{
		j=0;
		while(j<m && text[i+j]==pattern[j])
		{
			j++;
		}
		if(j==m)
			count+=1;
	}
	return count;
}
int non_overlap(char* text,char* pattern)
{
	int count=0;
	int j;
	int m=strlen(pattern);
	int n=strlen(text);
	for(int i=0;i<n-m+1;i++)
	{
		j=0;
		while(j<m && text[i+j]==pattern[j])
		{
			j++;
		}
		if(j==m)
		{
			count+=1;
			i=i+m-1;
		}
	}
	return count;
}
int main()
{
	char text[1000];
	char pattern[100];
	int count=0;
	scanf("%s",text);
	scanf("%s",pattern);
	count=overlap(text,pattern);
	printf("(overlap) Count=%d\n",count);
	count=non_overlap(text,pattern);
	printf("(non-overlap) Count=%d\n",count);
	return 0;
}
