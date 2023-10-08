#include<stdio.h>
#include<stdlib.h>
#define max 5
int stack[max];
int topA=-1,topB=max;
void pushA(int val)
{
	topA=topA+1;
	stack[topA]=val;
}
void pushB(int val)  
{
	topB=topB-1;
	stack[topB]=val;
}
int popA()
{
	int val;
	val=stack[topA];
	topA=topA-1;
	return val;
}
int popB()
{
	int val;
	val=stack[topB];
	topB=topB+1;
	return val;
}
int isoverflowA()
{
		if(topA==topB-1)
			return 1;
			else
			 return 0;	
}
int isoverflowB()
{
		if(topA==topB-1)
			return 1;
			else
			 return 0;	
}
int isunderflowA()
{
		if(topA==-1)
			return 1;
			else
			 return 0;	
}
int isunderflowB()
{
		if(topB==max)
			return 1;
			else
			 return 0;	
}
void displayA()
{
	int i;
	if(isunderflowA()==1)
	{
		printf("\nstack A is empty\n");
	}
		else
	{
		for(i=topA;i>-1;i--)
		printf("\t%d",stack[i]);
	}
}
void displayB()
{
	int i;
	if(isunderflowB()==1)
	{
		printf("\n stack B is empty\n");
	}
	else
	{
		for(i=topB;i<max;i++)
		printf("\t%d",stack[i]);
	}
}
void main()
{
	int opt,val;
	do
	{
		printf("\n***menu***");
		printf("\n push in stack a");
		printf("\n push in stack b");
		printf("\n pop in stack a");
		printf("\n pop in stack b");
		printf("\n display stack a");
		printf("\n display stack b");
		printf("\n exit");
		printf("\n enter your choice");
		scanf("%d",&opt);
		switch(opt)
		{
			case 1: if(isoverflowA()==1)
			printf("stack is overflow");
			else
			{
				printf("enter data to push:");
				scanf("%d",&val);
				pushA(val);
			}
			break;
			case 2: if(isoverflowB()==1)
			printf("stack is overflow");
			else
			{
				printf("enter data to push:");
				scanf("%d",&val);
				pushB(val);
		}
		    break;
		    case 3: if(isunderflowA()==1)
		    printf("cannot pop stack is underflow");
		    else
		    {
		    	val=popA();
		    	printf("%d has been popped",val);
			}
			break;
			case 4:  if(isunderflowB()==1)
		    printf("cannot pop stack is underflow");
		    else
		    {
		    	val=popB();
		    	printf("%d has been popped",val);		
	}
	        break;  
			case 5: printf("\n display stack A:\n");
			        displayA();
					break;
			case 6: printf("\n display stack B:\n");
			        displayB();
					break;	
			case 7: exit(0);
		}
}
while(1);
}
