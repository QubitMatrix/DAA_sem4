#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/time.h>
#include"sort.h"
void generate(int* a,int n)
{
	for(int i=0;i<n;i++)
	{
		a[i]=rand()%100000;
	}
}
void copy(int* org,int* new,int n)
{
	for(int i=0;i<n;i++)
	{
		new[i]=org[i];
	}
}
int main()
{
	struct timeval tv;
	int a[100000];
	int a1[100000];
	double elapse1,start1,end1,elapse2,start2,end2,elapse3,start3,end3;
	FILE *fp1,*fp2,*fp3;
	fp1=fopen("bub_time.dat","w");
	fp2=fopen("sel_time.dat","w");
	fp3=fopen("ins_time.dat","w");
	for(int inp=10000;inp<=100000;inp=inp+500)
	{
		generate(a1,inp);
		copy(a1,a,inp);
		gettimeofday(&tv,NULL);
		start1=tv.tv_sec+tv.tv_usec/1000000;
		bubblesort(a,inp);
		gettimeofday(&tv,NULL);
		end1=tv.tv_sec+tv.tv_usec/1000000;
		elapse1=(end1-start1)*1000;
		fprintf(fp1,"%d\t%lf\n",inp,elapse1);
		//printf("size %d bubble sort done\n",inp);
		
		copy(a1,a,inp);
		gettimeofday(&tv,NULL);
		start2=tv.tv_sec+tv.tv_usec/1000000;
		insertionsort(a,inp);
		gettimeofday(&tv,NULL);
		end2=tv.tv_sec+tv.tv_usec/1000000;
		elapse2=(end2-start2)*1000;
		fprintf(fp2,"%d\t%lf\n",inp,elapse2);
		//printf("size %d insertion sort done\n",inp);
		
		copy(a1,a,inp);
		gettimeofday(&tv,NULL);
		start3=tv.tv_sec+tv.tv_usec/1000000;
		selectionsort(a,inp);
		gettimeofday(&tv,NULL);
		end3=tv.tv_sec+tv.tv_usec/1000000;
		elapse3=(end3-start3)*1000;
		fprintf(fp3,"%d\t%lf\n",inp,elapse3);
		//printf("size %d selection sort done\n",inp);
	}
	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
	fclose(fp4);
	return 0;
}

		
