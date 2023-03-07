#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int left_cyclic(int n)
{
	int dig=(int)log2(n)+1;
	char rev_bin[dig+1];
	for(int i=0;i<dig;i++)
	{
		if(n & (1<<i))
			rev_bin[i+1]='1';
		else
			rev_bin[i+1]='0';
	}
	rev_bin[0]=rev_bin[dig];
	rev_bin[dig]='\0';
	int count=0;
	char token;
	int sum=0;
	while(count<dig)
	{
		token=rev_bin[count];
		sum+=((int)token-(int)('0'))*pow(2,count);
		count++;
	}
	return sum;
}
int josephus(int n)
{
	int arr[n];
	for(int i=0;i<n;i++)
		arr[i]=i+1;
	int counter=n;
	int pos=0;
	while(counter!=1)
	{
		for(int i=0;i<counter;i++)
		{
			if(arr[i])
				arr[(i+1)%counter]=0;	
		}
		pos=0;
		for(int i=0;i<counter;i++)
		{
			if(arr[i])
				arr[pos++]=arr[i];
		}
		counter=pos;
	}
	return arr[0];
}
int main()
{
	int n;
	scanf("%d",&n);
	int formula_ans=left_cyclic(n);
	int ans=josephus(n);
	printf("%d %d\n",formula_ans,ans);
	return 0;
}

