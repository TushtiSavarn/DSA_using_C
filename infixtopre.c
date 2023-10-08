//infix to prefix
#include<stdio.h>
#include<string.h>
#include<process.h>
#define size 20
char stack[size];//array of name stack
int top=-1;
char pop();
void push(char item);
int prcd(char symbol);
int isoperand(char symbol);
int isoperator(char symbol);
void convert(char infix[],char prefix[]);
char pop()
 {
 	char data;
 	data=stack[top];
 	top--;
 	return data;
 }
void push(char item)
 {
 	top++;
 	stack[top]=item;
 }
int prcd(char symbol)  
{ 
  switch(symbol)
   {
   	case'+':
   	case'-':
	        return 2;
	case'*':
	case'/':
	        return 4;
	case'^':
	case'$':
	        return 6;
	case'(':
	case')':
	        return 1;							
   }
}
int isoperand(char symbol)
 {
 	if((symbol>='A'&&symbol<='Z'||symbol>='a'&&symbol<='z'||symbol>='0'&&symbol<='9'))
 	 return 1;
 	else
	  return 0;
}
int isoperator(char symbol)
 {
 	switch(symbol)
 	 {
 	 	case'+':
 	 	case'-':
 	 	case'*':
		case'/':
		case'^':
		case'$':
		case'(':
		case')':
		        return 1;
		default:    
		       return 0; 		  	
	  }
 }
void convert(char infix[],char prefix[])
 {
 	int i,j=0;
	char symbol;
	 strrev(infix);
 	for(i=0;i<strlen(infix);i++)
 	 {
 	 	symbol=infix[i];
 	 	if(isoperand(symbol)==1)
 	 	 {
 	 	 	prefix[j]=symbol;
 	 	 	j++;
		   }
		else if(symbol==')')
		 push(symbol);
		else if(symbol=='(')
		{
			while(stack[top]!=')')
			{
			 prefix[j]=pop();
			 j++;	
			}
			pop();
		}
		else if(isoperator(symbol)==1)
		 {
		 	if(prcd(symbol)>prcd(stack[top]))
		 	 {
		 	  push(symbol);	
			  }
			else 
			{
			while(prcd(symbol)<=prcd(stack[top]))
			{
				prefix[j]=pop();
				j++;
				}	
			} 
			push(symbol); 
		  }
		else
		 {
		 	printf("Invalid symbol%c",symbol);
		 	exit(1);
		   } 
	}
  	  while(top!=-1)
	  {
	   prefix[j]=pop();
	   j++;
	  }
	 prefix[j]='\0'; 
  }
 void main()
 {
 	char infix[size],prefix[size] ;
 	printf("Enter infix expression\n");
 	gets(infix);
  	convert(infix,prefix);
 	strrev(prefix);
 	printf("Prefix expression\n");
 	puts(prefix);
  }
