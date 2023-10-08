//priority2nd
#include<stdio.h>
#include<stdlib.h>
#include<process.h>
#define size 5
int queue[size],pri[size];
int front,rear;
void shift(int a)
 {
 	int i;
 	for(i=rear;i>a;i++)
 	 {
 	 	queue[i]=queue[i-1];
 	 	pri[i]=pri[i-1];
	  }
 }
void sort(int data,int p)
 {
   int f=front,r=rear;
   if(p<pri[f])//highest priority
    {
    	shift(f);
    	queue[f]=data;
    	pri[f]=p;
	}
 else if(p>pri[r-1])//last priority	
  {
  	queue[r]=data;
  	pri[r]=p;
  }	
 else  //middle priority
  {
  	while(p>=pri[f])
  	 f++;
  	shift(f);
	queue[f]=data;
	pri[f]=p;   
   } 
 }
 void enqueue(int data,int p)
  {
  	if (rear==-1)
  	 {
  	 	front=0;
  	 	rear=0;
  	 	queue[rear]=data;
  	 	pri[rear]=p;
	   }
	else  
	 {
	   rear++;
	   sort(data,p);	
	  } 
  }
 int dequeue()
  {
  	int data;
  	data=queue[front];
  	front++;
  	if(front>rear)
  	 {
  	 	front=-1;
  	 	rear=-1;
  	  }
  	return data;  
   } 
  void display()
   {
   	int i;
   	printf("Front->\t");
   	for(i=front;i<=rear;i++)
   	  printf("%d\t",queue[i]);
   	printf("<-rear\n");  
   	 printf("\nfront-->\t");
   	for(i=front;i<=rear;i++)
	  printf("%d\t",pri[i]);
	printf("<-rear\n");     
	} 
 int isunderflow()
  {
  	if(front==-1)
  	 return 1;
  	else
	  return 0;
  }
 int isoverflow()
  {
  	if(rear==size-1)
  	 return 1;
  	else
	  return 0;
	
   } 
 void main()
  {
  	int data,ch,p;
  	front=-1;
  	rear=-1;
  	do{
	printf("Menu\n1 enqueue\n2dequeue\n3display\n4 exit");
  	scanf("%d",&ch);
  	switch(ch)
  	 {
  	 	case 1:
  	 		  if(isoverflow()==1)
  	 		   printf("Queue is overflow");
  	 		  else
				 {
				 	printf("Enter the data");
				 	scanf("%d",&data);
				 	printf("Enter the priority");
				 	scanf("%d",&p);
				 	enqueue(data,p);
				   } 
			  break;
		case 2:
		       if(isunderflow()==1)
			    printf("Queue underflow can't dequeue'");
			   else
			    {
			    	data=dequeue();
			    	printf("%d dequeued",data);
			    }
				break;
		case 3:
		       if(isunderflow()==1)
		        printf("Queue is empty");
			   else
			    display();
			    break;	
		case 4:
		       exit(0);
	    }	  
	  }
    while(ch>=1&&ch<=4); 
	  }	
