#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int sum(int* arr,int start,int end)
{
	int sum1=0;
	for(int i=start;i<end;i++)
		sum1+=arr[i];
	return sum1;
}
int fake_coins_2(int* arr,int start,int end)
{
	int sum1,sum2;
	if(end-start==1)
		return start;
	else
	{
		if((end-start)%2==0)
		{
			sum1=sum(arr,start,(start+end)/2);
			sum2=sum(arr,(start+end)/2,end);
			if(sum1>sum2)
				return fake_coins_2(arr,(start+end)/2,end);
			else
				return fake_coins_2(arr,start,(start+end)/2);
		}
		else
		{
			sum1=sum(arr,start,(start+end)/2);
			sum2=sum(arr,(start+end)/2,end-1);
			if(sum1>sum2)
				return fake_coins_2(arr,(start+end)/2,end);
			else if(sum2>sum1)
				return fake_coins_2(arr,start,(start+end)/2);
			else
				return end-1;
		}
	}			
}
int fake_coins_3(int* arr,int start, int end)
{
	//printf("%d %d\n",start,end);
	//sleep(1);
	int sum1,sum2;
	if(end-start==1)
		return start;
	else if(end-start==2)
	{
		if(arr[start]<arr[start+1])
			return start;
		else
			return start+1;
	}
	else
	{
		if((end-start)%3==0)
		{
			sum1=sum(arr,start,start+(end-start)/3);
			sum2=sum(arr,start+(end-start)/3,start+2*(end-start)/3);
			if(sum1<sum2)
				return fake_coins_3(arr,start,start+(end-start)/3);
			else if(sum1>sum2)
				return fake_coins_3(arr,start+(end-start)/3,start+2*(end-start)/3);
			else
				return fake_coins_3(arr,start+2*(end-start)/3,end);
		}
		else
		{
			sum1=sum(arr,start,start+(end-start)/3);
			sum2=sum(arr,start+(end-start)/3,start+2*(end-start)/3);
			if(sum1<sum2)
				return fake_coins_3(arr,start,start+(end-start)/3);
			else if(sum1>sum2)
				return fake_coins_3(arr,start+(end-start)/3,start+2*(end-start)/3);
			else
				return fake_coins_3(arr,start+2*(end-start)/3,end);
		}
			
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	int ans=fake_coins_2(arr,0,n);
	printf("%d %d\n",ans+1,arr[ans]);
	ans=fake_coins_3(arr,0,n);
	printf("%d %d\n",ans+1,arr[ans]);
	return 0;
}
