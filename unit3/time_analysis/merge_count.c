#include<stdio.h>
#include<sys/times.h>
#include<stdlib.h>
#include<math.h>
void getrand(int* arr,int n)
{
	int a;
	for(int i=0;i<n;i++)
	{
		a=rand()%100000;
		arr[i]=a;
	}
}

void merge(int* arr,int low,int mid,int high,int* count)
{
        int i=low;
        int j=mid+1;
        int k=low;
        int* t=calloc(high+1,sizeof(int));
        while(i<=mid && j<=high)
        {
                (*count)+=1;
				if(arr[i]<=arr[j])
                {
                        t[k++]=arr[i++];
                }
                else
                {
                        t[k++]=arr[j++];
                }
        }
        while(i<=mid)
        {
                t[k++]=arr[i++];
        }
        while(j<=high)
        {
                t[k++]=arr[j++];
        }
        for(int i=low;i<=high;i++)
        {
                arr[i]=t[i];
        }

}
void mergesort(int* arr,int low, int high,int* count)
{
        int mid;
        if(low<high)
        {
                mid=(low+high)/2;
                mergesort(arr,low,mid,count);
                mergesort(arr,mid+1,high,count);
                merge(arr,low,mid,high,count);
        }
}
int main()
{
	double elapse,start,end;
	FILE* fp=fopen("log.txt","w");
	FILE* fp1=fopen("count.txt","w");
	struct timeval tv;
	int* arr;
	int count;
	int counter=0;
	int step=1;
	for(int i=10;i<=15000;i+=step)
	{
		if(counter%10==0)
		{
			counter=0;
			step*=5;
		}
		arr=calloc(i,sizeof(int));
		getrand(arr,i);
		count=0;
		mergesort(arr,0,i-1,&count);
		fprintf(fp,"%d %lf\n",i,i*(log2(i)));
		fprintf(fp1,"%d %d\n",i,count);
		counter++;
	}
	return 0;
}
