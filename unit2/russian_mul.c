#include<stdio.h>
#include<stdlib.h>

int rmul_recursive(int m,int n)
{
	if(m==1)
		return n;
	else
	{
		if(m%2==0)
			return rmul_recursive(m/2,2*n);
		else
			return rmul_recursive(m/2,2*n)+n;
	}
}
int rmul_iterative(int m,int n)
{
	int sum=0;
	while(m!=1)
	{
		if(m%2==0)
		{
				m=m/2;
				n=2*n;
		}
		else
		{
				m=m/2;
				sum+=n;
				n=2*n;
		}
	}
	return n+sum;
}
int main()
{
	int m,n,ans;
	scanf("%d %d",&m,&n);
	ans=rmul_recursive(m,n);
	printf("Recursive:%d\n",ans);
	ans=rmul_iterative(m,n);
	printf("Iterative:%d\n",ans);
	return 0;
}
