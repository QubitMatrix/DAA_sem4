#include<stdio.h>
#include<stdlib.h>
#include<math.h>

long power(int a,int n)
{
	long power1;
	if(n==1)
		return a;
	else if(n%2==0)
	{
		power1=power(a,n/2);
		return(power1*power1);
	}
	else
	{
		power1=power(a,n/2);
		return power1*power1*a;
	}
}
int main()
{
	int a,n;
	scanf("%d",&a);
	scanf("%d",&n);
	long res=power(a,n);
	printf("%ld\n",res);
	return 0;
}
