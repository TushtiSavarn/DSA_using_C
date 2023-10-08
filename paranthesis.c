#include<stdio.h>
#include<string.h>
#define MAX 10
int top =-1;
char stk[MAX];
void push(char);
char pop();
int match(char exp[],char temp);
void main()
{
char exp[MAX],temp;
int i,flag=1;
printf("enter an expression:");
gets(exp);
for(i=0;i<strlen(exp);i++)
{
		if(exp[i]=='(')
		 push(exp[i]);
		else if(exp[i]);
		{
				temp=pop();
				flag=match(exp,temp);
		}
}
if(top=-1)
flag=0;
if(flag==1)
		printf("/n valid experssion");
else
		printf("/n invalid experssion");
}
void push(char val)
{ 
		stk[++top]=val;
}
char pop()
{
	return(stk[top--]);
}
int match (char exp [],char temp)
{
	    int i;
	    for(i=0;i<strlen(exp);i++)
	    {
	    	if((exp[i]==')')&&(temp='('))
	    	return 1;
	    	else return 0;
		}
}
		
