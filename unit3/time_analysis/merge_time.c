#include<stdio.h>
#include<sys/times.h>
#include<stdlib.h>

void getrand(int* arr,int n)
{
	int a;
	for(int i=0;i<n;i++)
	{
		a=rand()%100000;
		arr[i]=a;
	}
}

void merge(int* arr,int low,int mid,int high)
{
        int i=low;
        int j=mid+1;
        int k=low;
        int* t=calloc(high+1,sizeof(int));
        while(i<=mid && j<=high)
        {
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
void mergesort(int* arr,int low, int high)
{
        int mid;
        if(low<high)
        {
                mid=(low+high)/2;
                mergesort(arr,low,mid);
                mergesort(arr,mid+1,high);
                merge(arr,low,mid,high);
        }
}
int main()
{
	double elapse,start,end;
	FILE* fp=fopen("out.txt","w");
	struct timeval tv;
	int* arr;
	for(int i=5000;i<=15000;i+=500)
	{
		arr=calloc(i,sizeof(int));
		getrand(arr,i);
		gettimeofday(&tv,NULL);//NULL - timezone
		start=tv.tv_sec*1000+tv.tv_usec/1000;
		mergesort(arr,0,i-1);
		gettimeofday(&tv,NULL);
		end=tv.tv_sec*1000+tv.tv_usec/1000;
		elapse=(end-start);
		fprintf(fp,"%d %lf\n",i,elapse);
	}
	return 0;
}
