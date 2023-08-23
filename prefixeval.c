//prefix evalutation
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
int evalu(char prefix[]);
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
  int evalu(char prefix[])
   {
   	int i;
   	char symbol;
   	int op1,op2,result;
    strrev(prefix);
   	for(i=0;i<strlen(prefix);i++)
   	 {
   	 	symbol=prefix[i];
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
	  	 		    result=op1%op2;
	  	 		    break;
	  	 	case'+':
			        result=op1+op2;
					break;
			case'-':
			        result=op1-op2;
					break;
			case'*':
			       result=op1*op2;
				   break;
			case'/':
			        result=op1/op2;
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
   	char prefix[max];
   	int ans;
   	printf("\nEnter prefix string\n");
   	gets(prefix);
   	ans=evalu(prefix);
   	printf("\nAnswer=%d",ans);
   }
