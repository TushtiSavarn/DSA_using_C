//circular queue implementation
#include<stdio.h>
#include<process.h>
#define size 10
struct queue
{
 int arr[size];
 int front,rear;
};
typedef struct queue queue;
void main()
 {
 	int ch,data;
 	queue q;
 	q.rear=q.front=-1;
 	int isoverflow(queue q)
 	 {
 	 	if((q.rear==size-1&&q.front==0)||(q.rear==q.front-1)) //linear cond.||circular cond.
 	 	 return 1;
 	 	else
		  return 0;  
	  }
	int isunderflow(queue q)  
	 {
	 	if(q.front==-1)
	 	 return 1;
	 	else 
		 return 0; 
	 }
	void enqueue(queue *pq,int data)
	 {
	 	if(pq->rear==-1) //1st element to be insert
	 	 {
	 	 	pq->rear++;
	 	 	pq->front++;
		  }
		 else if(pq->rear==size-1) //bringing rear to 1st to make circle
		 {
		 	pq->rear=0;
		 } 
		else //some elements are there in queue
		 {
		 	pq->rear++;
		  }
		 pq->arr[pq->rear]=data;  
		 printf("%d enqueued",data); 
	  } 
	int dequeue( queue *pq)
	 {
	 	int data;
	 	if(pq->rear==pq->front)//last element delete
	 	{
	 		data=pq->arr[pq->front];
	 		pq->front=pq->rear=-1;
		 }
		 else if(pq->front==size-1) 
		  {
		  	data=pq->arr[pq->front];
		  	pq->front=0;
		  }
		else // delete other than last 
		{
			data=pq->arr[pq->front];
			pq->front++;
		 } 
		return data; 
	   }  
	void display(queue q)
	 {
	 	int f,r;
	 	f=q.front;
		r=q.rear;
		if(q.front==-1)
		 printf("Queue empty");
		if(f<=r)
		 {
		 	while(f<=r)
		 	{
		 		printf("\t%d",q.arr[f]);
		 		f++;
			 }
			} 
		else
		 {
		 	while(f<=size-1)
		 	 {
		 	 	printf("\t%d",q.arr[f]);
		 	 	f++;
			  }
			  f=0;
			   while(f<=r)
			    {
			    	printf("\t%d",q.arr[f]);
			    	f++;
				}
			   }	  
		}   
	
	do
	 {
	 	printf("\nMenu\n1-enqueue\n2-dequeue\n4-display\n5-exit\n");
	 	scanf("%d",&ch);
	 	switch(ch)
	 	{
	 		case 1:
			        if(isoverflow(q)==1) 
	 		         printf("\nqueue overflow hence can't enqueue");
	 		        else
					 {
					 	printf("\nEnter the data to enqueue");
					 	scanf("%d",&data);
					 	enqueue(&q,data);
					  } 
					break;  
			case 2:
				   if(isunderflow(q)==1)
				     printf("\nqueue underflow hence can't dequeue");
				    else
					 {
					 	data=dequeue(&q);
					 	printf("\nData dequeued=%d",data);
					  } 
					break;
			/*case 3:
			       lenght(q);
				   break;*/
			case 4:
			       display(q);
				   break;
			case 5:
			       exit(0);	
				   break;   	   		  
	  
		 }
	 }
	while(ch>=1&&ch<=5);
 }
