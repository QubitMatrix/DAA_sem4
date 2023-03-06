#include<stdio.h>
#include<stdlib.h>
struct dict
{
	int key;
	int val;
};
typedef struct dict dict;
int mode(int* arr,int n)
{
	int count=0;
	dict dic[n];
	int mode=0;
	int max=0;
	int flag=0;
	for(int i=0;i<n;i++)
	{
		flag=0;
		for(int j=0;j<count;j++)
		{
			if(dic[j].key==arr[i])
			{
				flag=1;
				dic[j].val+=1;
			}
		}
		if(flag==0)
		{
			dic[count].val=0;
			dic[count++].key=arr[i];
		}
	}
	for(int i=0;i<count;i++)
	{
		if(dic[i].val>max)
		{
			mode=dic[i].key;
			max=dic[i].val;
		}
	}
	return mode;
}


int main()
{
	int n;
	scanf("%d",&n);
	int* arr=calloc(n,sizeof(int));
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	int mode1=mode(arr,n);
	printf("%d\n",mode1);
	return 0;
}
