#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#define var 11


struct node
{
  	int data;
  	struct node* link;
};

int main()
{	

	setbuf(stdout,NULL);
	setbuf(stdin,NULL);
	setbuf(stderr,NULL);

	int randomfunc(int ,int );
	void func2(struct node **,int );
	int func1(int );
	int func3(struct node *);

	time_t var1,begin,end1;
	srand((unsigned)time(&var1));
	time(&begin);

	srand(time(NULL));

	char pt1[7]="3h8t1e";
	char pt2[7];
	char x;
	
	for(int i=0;i<strlen(pt1);i++)
	{
		if((*(pt1+i) >= 'a') && (*(pt1+i) <= 'z'))
		{

			if((x = pt1[i] + var) <= 'z')
			{
				pt2[i]=x;				
			}
			else
			{
				int temp='z' - pt1[i];
				char final='a' + (temp-2);
				pt2[i]=final;				
			}
		}
		else
		{
			pt2[i]=pt1[i];
		}
	}

	int s=0;
	int end;
	char trial[7];

	while(pt2[s] != '\0')
	{
		s++;
	}

	end=s-1;

	for(int j=0;j<s;j++)
	{
		trial[j]=pt2[end];
		end--;
	}

	trial[s]='\0';

	/*printf("%s\n",pt2 );
	printf("%s\n",trial );*/

	char input1[7];
	scanf("%[^\n]%*c", input1); 
	if(strncmp(trial,input1,strlen(trial)))
	{
		exit(1);
	}

	int elements[9];
	int total=0;

	for(int g=0;g<9;g++)
	{
		elements[g]=randomfunc(100,10000);
		printf("%d\n",elements[g]);
		total+=elements[g];
	}

	int avg=total/9;
	//printf("avg=%d\n",avg);
	int SD=0;
	for (int h = 0; h < 9; ++h)
	{
        SD += pow(elements[h] - avg, 2);
	}

    int SD_final=sqrt(SD / 9);
    //printf("SD=%d\n",SD_final);

    int sd;
    scanf("%d",&sd);

    if(sd == SD_final)
    {
    	system("cat small_chunk.txt");
    	printf("\n");
    }
    else
    {
    	printf("Nothing for u here\n");
    	exit(1);
    }
    

    struct node *head=NULL;
    int v=randomfunc(5000,10000);
    printf("%d\n",v);
    int sum1=0;
    

    for(int d=100;d<v;d++)
    {
    	sum1=func1(d);
    	if((sum1%2==0) && (sum1%3==0))
    	{
    		//printf("done\n");
    		func2(&head, d);
    		//insert_tail(&head, sum1);
    	}		
    		
    }
    //printf("%d\n",sum1);
    //display(head);
    int altsum;
    altsum=func3(head->link);

    //printf("%d\n",altsum);
    int input2;
    scanf("%d",&input2);

	time(&end1);
	double z=end1-begin;

    if((input2==altsum) && (z<5))
    {
    	system("cat big_chunk.txt");
    }
    else
    {
    	printf("Nothing for u here\n");
    }
	return 0;

}
    	
int randomfunc(int a,int b)
{
	return ((rand() % (b-a+1)) + a);
}

void func2(struct node **p,int x)
{	
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->data=x;

	if(*p==NULL)
	{
		*p=temp;
		temp->link=NULL;
	}
	else
	{
		temp->link=*p;
		*p=temp;
	}
}

int func1(int a)
{
	int r;
    int sum=0;
    while(a>0)
    {
    	r=a%10;
    	sum+=r;
    	a=a/10;
    }
    	
    return sum;
}

int func3(struct node *p)
{
	int sum=0;
	for(int i=0;p!=NULL;i++)
	{
		if(i%2==0)
		{
			sum+=p->data;
		}
		p=p->link;
	}
	return sum;
}