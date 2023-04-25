#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int find_sum(int person,int* final,int** mat)//sum of previously finalized persons
{
	int sum=0;
	for(int i=person;i>=0;i--)
		sum+=mat[i][final[i]];
	return sum;
}
void job_assignment(int person,int no_per,int* busy,int* taken,int** mat,int** min_vector,int* final,int* ans,int* sol_vector,int** prune)
{
	int minval=999999;
	int minpos=0;
	int sum=0;
	busy[person]=1; //set person to busy
	for(int j=0;j<no_per;j++) //iterate through all possibilites of jobs and store their bounds
	{
		sum=0;
		if(taken[j]) //if job taken go to next job
			continue;
		taken[j]=1; //set job to taken
		final[person]=j; //set this job as final in this trial
		for(int x=0;x<no_per;x++) //find min of all non busy persons
		{
			if(busy[x]==0)
			{
				minval=999999;
				for(int y=0;y<no_per;y++)
				{
					if(taken[y]==0 && minval>mat[x][y])//to find min in each non busy row
						minval=mat[x][y];
				}
				sum+=minval;
			}
		}
		min_vector[person][j]=sum+find_sum(person,final,mat);//add the min of all non busy persons with the sum of already fixed persons jobs
		taken[j]=0; //reset job as not taken to use for next iteration
		final[person]=-1; //reset final job of person for next iteration
	}
	for(int i=0;i<no_per;i++)//check all the estimated bounds to choose min and proceed
	{
		if(min_vector[person][i]<min_vector[person][minpos])
			minpos=i;
	}
	taken[minpos]=1; //set the taken of job giving min bound
	final[person]=minpos; //set it as final job
	if(person+1<no_per-1) //repeat till no_per-1 have their jobs fixed
	{
		job_assignment(person+1,no_per,busy,taken,mat,min_vector,final,ans,sol_vector,prune);
	}
	else //check if the answer is the best compared to all other branches
	{
		if(*ans!=min_vector[person][minpos]) //if ans is not same as the best found, set the ans and sol_vector
		{
			*ans=min_vector[person][minpos];
			for(int i=0;i<no_per;i++)
			{
				sol_vector[i]=final[i];
			}
		}

		for(int pos=person-1;pos>=0;pos--)//backtrack to all other branches to see if a better possibility exists
		{
			busy[pos+1]=0;
			taken[final[pos+1]]=0;
			final[pos+1]=-1;
			prune[pos][final[pos]]=1;//prune the branch that was already used
			for(int i=0;i<no_per;i++)
			{
				if(min_vector[pos][i]<*ans && prune[pos][i]==0)//if a branch has lesser bound than the best answer so far and it is not a pruned branch
				{
					taken[final[pos]]=0;
					final[pos]=i;
					taken[i]=1;
					job_assignment(pos+1,no_per,busy,taken,mat,min_vector,final,ans,sol_vector,prune);
				}
			}
		}
	}
}
void freeall(int* busy,int* taken,int* sol_vector,int* final,int** mat,int** min_vector,int** prune,int no_per)//free all dynamic allocations
{
	free(taken);
	free(busy);
	free(sol_vector);
	free(final);
	for(int i=0;i<no_per;i++)
	{
		free(min_vector[i]);
		free(mat[i]);
		free(prune[i]);
	}
	free(min_vector);
	free(mat);
	free(prune);
}
int main()
{
	int no_per;
	int ans=0;
	printf("Enter the number of persons\n");
	scanf("%d",&no_per);
	int** mat=calloc(no_per,sizeof(int*));//store input matrix
	for(int i=0;i<no_per;i++)
		mat[i]=calloc(no_per,sizeof(int));
	int* busy=calloc(no_per,sizeof(int));//to track persons assigned with a job already
	int* taken=calloc(no_per,sizeof(int));//to track jobs taken already
	int** min_vector=calloc(no_per,sizeof(int*));//to keep track of the lower bound at each node in backtracking tree
	int* final=calloc(no_per,sizeof(int));//to store the final job assigned to each person in each trial
	int* sol_vector=calloc(no_per,sizeof(int));//to store the job assigned to each person for the best answer  
	int** prune=calloc(no_per,sizeof(int*));//prune out the branches already tried
	for(int i=0;i<no_per;i++)
	{
		min_vector[i]=calloc(no_per,sizeof(int));
		prune[i]=calloc(no_per,sizeof(int));
		final[i]=-1;
		for(int j=0;j<no_per;j++)
			min_vector[i][j]=999999;
	}
	printf("Enter the matrix\n");
	for(int i=0;i<no_per;i++)
	{
		for(int j=0;j<no_per;j++)
			scanf("%d",&mat[i][j]);
	}
	job_assignment(0,no_per,busy,taken,mat,min_vector,final,&ans,sol_vector,prune);
	printf("Min assignment sum=%d\n",ans);
	free(taken);
	taken=calloc(no_per,sizeof(int));
	for(int i=0;i<no_per;i++)
	{
		if(sol_vector[i]!=-1)
			taken[sol_vector[i]]=1;
	}
	for(int i=0;i<no_per;i++)
	{
		if(taken[i]==0)
			sol_vector[no_per-1]=i;
	}

	printf("Assignment of jobs: ");
	for(int i=0;i<no_per;i++)
			printf("%d ",sol_vector[i]+1);
	printf("\n");
	freeall(busy,taken,sol_vector,final,mat,min_vector,prune,no_per);
	return 0;
}
