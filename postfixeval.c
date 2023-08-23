//postfix evalutation
#include<stdio.h>
#include<string.h>
#include<process.h>
#define max 20
struct stack
{
	int data[max];
	int top;
}s;
int pop();
void push(int item);
int is_digit(char c);
int evalu(char postfix[]);
 int is_operator(char symbol);
int pop()
 {
 	int ret;
 	if(s.top==-1)
     {
     	printf("\nStack empty");
     	return -111;
     }
    else
	{
		ret=s.data[s.top];
		--s.top;
		return ret;
	 } 
 }
void push(int item)
 {
 	if(s.top==max-1)
 	 {
 	 	printf("\nStack full");
 	 }
 	else
	  {
	  	++s.top;
	  	s.data[s.top]=item;
	   } 
  } 
 int is_digit(char c) 
  {
  	if((c>='0')&&(c<='9'))
  	 return 1;
  	else
	  return 0; 
  }
  int evalu(char postfix[])
   {
   	int i;
   	char symbol;
   	int op1,op2,result;
   	for(i=0;i<strlen(postfix);i++)
   	 {
   	 	symbol=postfix[i];
   	 	 while(symbol==' '||symbol=='\t')
   	 	 {
   	 	 	i++;
		 }
   		 if(is_digit(symbol)==1)
		 {
		 	push(symbol-48);
		 }

	 else if(is_operator(symbol)==1)
	  {
	  	op1=pop();
	  	op2=pop();
	  	switch(symbol)
	  	 {
	  	 	case'%':
	  	 		    result=op2%op1;
	  	 		    break;
	  	 	case'+':
			        result=op2+op1;
					break;
			case'-':
			        result=op2-op1;
					break;
			case'*':
			       result=op2*op1;
				   break;
			case'/':
			        result=op2/op1;
					break;
						   					    
		   }
		  push(result); 
		}
	 else
	  {
	   printf("\nInvalid operator");
	   exit(1);
	  }	
	 if(s.top!=-1)
	  {
	  	result=pop();
	  	return result;
	  }  	 	 
	}
   }
 int is_operator(char symbol)
   {
   	switch(symbol)
   	 {
   	 	case'+':
   	 	case'-':
		case'*':
		case'/':
		case'%':
		case'(':
		case')':	
		        return 1;
		default:
		        return 0;				
		}
   }
   void main()
   {
   	char postfix[max];
   	int ans;
   	printf("\nEnter postfix string\n");
   	gets(postfix);
   	ans=evalu(postfix);
   	printf("\nAnswer=%d",ans);
   }
