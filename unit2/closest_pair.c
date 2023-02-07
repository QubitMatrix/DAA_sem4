#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	int n;
	scanf("%d",&n);
	int arr[n][2];
	int ans[2][2];
	double dis=0;
	double mindis=10000;
	for(int i=0;i<n;i++)
	{
		scanf("%d %d",&arr[i][0],&arr[i][1]);
	}
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			dis=pow((pow((arr[i][0]-arr[i+1][0]),2)+pow((arr[i][1]-arr[i+1][1]),2)),0.5);
			mindis=mindis>dis?dis:mindis;
			//printf("%d %d %d %d %f %f\n",arr[i][0],arr[i][1],arr[j][0],arr[j][1],dis,mindis);
			if(mindis==dis)
			{
				//printf("a%d %d %d %d %f\n",arr[i][0],arr[i][1],arr[j][0],arr[j][1],mindis);
				ans[0][0]=arr[i][0];
				ans[0][1]=arr[i][1];
				ans[1][0]=arr[i+1][0];
				ans[1][1]=arr[i+1][1];
			}
		}
	}
	printf("(%d,%d),(%d,%d)\n",ans[0][0],ans[0][1],ans[1][0],ans[1][1]);

	return 0;
}
