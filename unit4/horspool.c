#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void init_table(int* shift_table,int n)
{
	for(int i=0;i<26;i++)
		shift_table[i]=n;
}
void preprocess(int* shift_table,char* pattern)
{
	int ind;
	for(int i=0;i<strlen(pattern)-1;i++)
	{
		ind=pattern[i]-'a';
		shift_table[ind]=strlen(pattern)-i-1;
	}
}

void string_match(int* shift_table,char* pattern,char* text)
{
	int count;
	int star_pos=strlen(pattern)-1;
	char star_char;
	int cmp=0;
	int occurance=0;
	while(star_pos<strlen(text))
	{
		star_char=text[star_pos];
		//printf("%d %c\n",star_pos,star_char);
		count=0;
		for(int i=0;i<strlen(pattern);i++)
		{
			//printf("%c %c\n",pattern[strlen(pattern)-1-i],text[star_pos-i]);
			cmp++;
			if(pattern[strlen(pattern)-i-1]!=text[star_pos-i])
			{
				star_pos+=shift_table[star_char-'a'];
				break;
			}
			else
			{
				count+=1;
			}
		}
		if(count==strlen(pattern))
		{

				printf("Occurance at %d\n",star_pos-(int)strlen(pattern)+1);
				occurance+=1;
				star_pos+=shift_table[star_char-'a'];
		}
	}
	if(occurance==0)
		printf("No occurances\n");
	printf("No. of occurances=%d\nComparisons:%d\n",occurance,cmp);
}

int main()
{
	char text[1000];
	char pattern[100];
	scanf("%s",text);
	scanf("%s",pattern);
	int* shift_table=calloc(26,sizeof(int));
	init_table(shift_table,strlen(pattern));
	preprocess(shift_table,pattern);
	string_match(shift_table,pattern,text);
	//printf("%d",ans);
	return 0;
}
