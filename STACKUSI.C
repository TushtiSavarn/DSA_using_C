//Stack implementation using structure
#include<stdio.h>
#include<conio.h>
#include<process.h>
#define size 10
struct stack
 {
  int arr[size];
  int top;
 };
 typedef struct stack stack;
void main()
 {
  int ch,data;
  stack s;
  s.top=-1;
  clrscr();
  do
   {
    printf("\nMenu\n1-push\n2-pop\n3-peep\n4-display\n5-exit");
    scanf("%d",&ch);
    switch(ch)
     {
      case 1:
	     if(isoverflow(s.top))
	      printf("Overflow");
	     else
	      {
	       printf("\nEnter the data");
	       scanf("%d",&data);
	       push(&s,data);
	      }
	     break;
     case 2:
	    if(isunderflow(s.top))
	     printf("Underflow");
	    else
	     {
	      data=pop(&s);
	      printf("\n%dPoped data=",data);
	     }
	    break;
    case 3:
	   data=peep(s);
	   printf("\n%dis the element at top",data);
	   break;
   case 4:
	  display(s);
	  break;
   case 5 :
	  exit(0);
 }
}
 while(ch>=1&&ch<=5);
getch();
}
int push(stack *ps,int data)
 {
  ps->top=ps->top+1;
  ps->arr[ps->top]=data;
  printf("data pushed");
  return 0;
 }
int pop(stack *ps)
 {
  int data;
  data=ps->arr[ps->top];
  ps->top=ps->top-1;
  return data;
 }
int isoverflow(stack s)
 {
  if(s.top==size-1)
   return 1;
  else
   return 0;
 }
int isunderflow(stack s)
 {
  if(s.top==-1)
   return 1;
  else
   return 0;
 }
 int peep(stack s)
  {
    int data;
    data=ps->arr[ps->top];
    return data;
   }

int display(stack s)
 {
  int i;
  for(i=s.top;i>=0;i--)
  printf("\narr[%d]=%d\n",i,ps->arr[ps->top]);
  return 0;
 }
