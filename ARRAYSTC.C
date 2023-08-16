//Stack using array
#include<stdio.h>
#include<conio.h>
#include<process.h>
#define size 10
void main()
 {
  int arr[size],top=-1,ch,data;
  clrscr();
  do
   {
    printf("\nMenu\n1-push\n2-pop\n3-peep\n4-display\n5-exit");
    scanf("%d",&ch);
    switch(ch)
     {
      case 1:
	     if(isoverflow(top))
	      printf("Overflow");
	     else
	      {
	       printf("\nEnter the data");
	       scanf("%d",&data);
	       push(arr,&top,data);
	      }
	     break;
     case 2:
	    if(isunderflow(top))
	     printf("Underflow");
	    else
	     {
	      data=pop(arr,&top);
	      printf("\n%dPoped data=",data);
	     }
	    break;
    case 3:
	   data=peep(arr,top);
	   printf("\n%dis the element at top",data);
	   break;
   case 4:
	  display(arr,top);
	  break;
   case 5 :
	  exit(0);
 }
}
 while(ch>=1&&ch<=5);
getch();
}
int push(int arr[],int*t,int data)
 {
  *t=*t+1;
  arr[*t]=data;
  printf("data pushed");
  return 0;
 }
int pop(int arr[],int*t)
 {
  int data;
  data=arr[*t];
  *t=*t-1;
  return data;
 }
int isoverflow(int t)
 {
  if(t==size-1)
   return 1;
  else
   return 0;
 }
int isunderflow(int t)
 {
  if(t==-1)
   return 1;
  else
   return 0;
 }
 int peep(int arr[],int t)
  {
    int data;
    data=arr[t];
    return data;
   }

int display(int arr[],int t)
 {
  int i;
  for(i=t;i>=0;i--)
  printf("\narr[%d]=%d\n",i,arr[i]);
  return 0;
 }
