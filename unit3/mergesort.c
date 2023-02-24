#include<stdio.h>
#include<stdlib.h>

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
void mergesort(int* arr,int low, int high,int* count,int* counter)
{
        *counter=*counter+1;
        int mid;
        if(low<high)
        {
                mid=(low+high)/2;
                mergesort(arr,low,mid,count,counter);
                mergesort(arr,mid+1,high,count,counter);
                merge(arr,low,mid,high,count);
        }
        printf("In merge sort %d(%d %d), count=%d\n",*counter,low,high,*count);
}

int main()
{
        int n;
        scanf("%d",&n);
        int* arr=calloc(n,sizeof(int));
        for(int i=0;i<n;i++)
        {
                scanf("%d",&arr[i]);
        }
        int counter=0;
        int count=0;
        mergesort(arr,0,n-1,&count,&counter);
        for(int i=0;i<n;i++)
                printf("%d ",arr[i]);
        printf("\n");
        printf("%d\n",count);
        free(arr);
        return 0;
}
