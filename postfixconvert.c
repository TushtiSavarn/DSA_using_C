#include<stdio.h>
#include<string.h>
#include<process.h>
#define size 20
char stack[size];
int top=-1;
char pop();
void push(char item);
int prcd(char symbol);
int isoperand(char symbol);
int isoperator(char symbol);
void convert(char infix[],char postfix[]);
char pop()
 {
 	char a;
 	a=stack[top];
 	top--;
 	return a;
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
		default:
		        return 0;	    				   	
	   }
  }
 int isoperand(char symbol) 
  {
 	if((symbol>='a'&&symbol<='z'||symbol>='A'&&symbol<='Z'||symbol>='0'&&symbol<='9'))
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
  void convert(char infix[],char postfix[])
   {
   	int i,j=0,symbol;
   	for(i=0;i<strlen(infix);i++)
   	 {
   	 	symbol=infix[i];
   	 	 if(isoperand(symbol)==1)
   	 	  {
   	 	  	postfix[j]=symbol;
   	 	  	j++;
		  }
		  else if(symbol=='(')
		  {
		  	push(symbol);
		  }
		 else if(symbol==')')
		  {
		    while(stack[top]!='(')
		     {
		     	postfix[j]=pop();
		     	j=j+1;
			 }
			 pop(); 
		   }
		 else if(isoperator(symbol)==1)
		  {
		  	if (prcd(symbol)<=prcd(stack[top]))
		  	 {
		  	 	postfix[j]=pop();
		  	 	j=j+1;
		      }
		  	 	push(symbol);
		  }
	     else
		 {
		 	printf("\nInvalid symbol%c",symbol);
		 	exit(1);
		}   
  }
		while(top!=-1)
		 {
		 	postfix[j]=pop();
		 	j=j+1;
		 }
}
	void main()
	 {
	 	char infix[10],postfix[10];
	 	printf("Enter the infix expression\n");
	 	gets(infix);
	 	convert(infix,postfix);
	 	printf("Postfix expression =\n");
	 	puts(postfix);
	   }   
   
