//parenthesis checking
#include<stdio.h>
#include<conio.h>
#define size 20
void push(char ch);
char pop();
int match(char a,char b);
int isbalanced(char exp[]);
char stack[size];
int top=-1;
int i;
void main()
{
	char exp[size];
	printf("Input expression:");
	gets(exp);
	int ans;
	ans=isbalanced(exp);
	if(ans==1)
	{
		printf("valid\n");
	}
	else
	{
		printf("Invalid\n");
	}
}
int isbalanced(char exp[])
{
	int i;
	char temp;
	for(i=0;i<strlen(exp);i++)
	{
		if(exp[i]=='('||exp[i]=='{'||exp[i]=='[')
		push(exp[i]);
		if(exp[i]==')'||exp[i]=='}'||exp[i]==']')
		{
			if(top==-1)
			{
				printf("Right are more %c\n",exp[i]);
				return 0;
			}
			else
			{
				temp=pop();
				if(match(temp,exp[i])==0)
				{
					printf("mismatched\n");
					printf("%c and %c",temp,exp[i]);
					return 0;
				}
			}
}}
			if(top==-1)
			{
				printf("balanced\n");
				return 1;
			}
			else
			{
				printf("left are more\n");
				return 0;
			}
		
	
}
int match(char a,char b)
{
	if(a=='['&&b==']')
	return 1;
	if(a=='{'&&b=='}')
	return 1;
	if(a=='('&&b==')')
	return 1;
	return 0;
}
void push(char ch)
{
	++top;
	stack[top]=ch;
}
char pop()
{
	char data;
	data=stack[top];
	top--;
	return data;
}
