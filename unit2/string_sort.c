#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define HASHSIZE 100007
#define STRINGLEN 30
void sort_string(char** str_arr,int n)
{
	int min;
	char* t=calloc(100,sizeof(char));
	for(int i=0;i<n-1;i++)
	{
		min=i;
		for(int j=i+1;j<n;j++)
		{
			if(strcmp(str_arr[j],str_arr[min])<0)
				min=j;
		}
		t=str_arr[i];
		str_arr[i]=str_arr[min];//strcpy(a,b) if not allocated as pointer of pointers
		str_arr[min]=t;
	}
}
unsigned long get_hash(char* s)
{
	unsigned long hashval=0;
	char token=s[0];
	int count=1;
	while(token!='\0')
	{
		hashval=token+31*hashval;
		token=s[count++];
	}
	return hashval% HASHSIZE ;
}
/*void free_all(char** arr,int n,char** hash)
{
}*/
int main()
{
	int n;
	char* search=calloc(STRINGLEN,sizeof(char));
	unsigned long hashval=0;
	scanf("%d",&n);
	char** str_arr=calloc(n,sizeof(char*));
	char** hash=calloc(HASHSIZE, sizeof(char*));
	for(int i=0;i<HASHSIZE;i++)
	{
		hash[i]=calloc(STRINGLEN,sizeof(char));
	}

	for(int i=0;i<n;i++)
	{
		str_arr[i]=calloc(STRINGLEN,sizeof(char));
		scanf("%s",str_arr[i]);
		hashval=get_hash(str_arr[i]);
		printf("Hash value of %s is %ld\n",str_arr[i],hashval);
		hash[hashval]=str_arr[i];
	}
	scanf("%s",search);
	hashval=get_hash(search);
	if(hash[hashval]==0)
		printf("Not found\n");
	else
		printf("Found\n");
	sort_string(str_arr,n);
	printf("After sorting:\n");
	for(int i=0;i<n;i++)
	{
		printf("%s\n",str_arr[i]);
	}
//free_all(str_arr,n,hash);

	for(int i=0;i<n;i++)
	{
		free(str_arr[i]);
	}
	free(str_arr);
	for(int i=0;i<HASHSIZE;i++)
	{
		printf("%d\n",i);
		free(hash[i]);
		//hash[i]=NULL;
	}
	free(hash);
	return 0;
}
