#include<stdio.h>
#include<process.h>
# define max 10
struct queue
{
	int arr[max];
	int front,rear;
	};
	typedef struct queue queue;
	int isoverflow(queue q)
	{
		if(q.rear==max-1)
		{
			return 1;
		}
		else
		{
			return 0;
		}
}
	int isunderflow(queue q)
	{
		if(q.front==-1)
		{
			return 1;
		}
		else
			return 0;
	}
	void enqueue(queue *pq,int data)
	{
		if(pq->rear==-1)
		{
			pq->front++;
			pq->rear++;
			pq->arr[pq->rear]=data;
			//pq->rear=pq->rear+1;
		}                          
		else
		{
			pq->rear++;
			 pq->arr[pq->rear]=data;
			}
			
		}
int dequeue(queue *pq)

	{
		int data;
		if(pq->rear==pq->front)
		{
		data=pq->arr[pq->front];
		pq->front=pq->rear=-1;
	}
	else
	{
		data=pq->arr[pq->front];
		pq->front=pq->front+1;
	}

return data;
}
void display(queue q)
 {
 	int i;
 	if(q.front==-1)
 	{
 		printf("\n queue is em pty\n");
	 }
	 else
	 {
 	for(i=q.front;i<=q.rear;i++)
 	{
 		printf("\narr[%d]=%d\n",i,q.arr[i]);
	 }
 }
}
 void main()
 {
 	queue q;
 	int ch,data;
	q.rear=q.front=-1;
	do
	{
	printf("\n--menu--\n");
 	
 	printf("\n 1: enqueue\n");
 	printf("\n 2: dequeue\n");
 	printf("\n 3: display\n");
 	printf("\n 4:exit\n");
 	printf("\n enter the choice");
 	scanf("%d",&ch);
 	switch(ch)
 	{
 		case 1:if(isoverflow(q)==1)
 	              
 	              	printf("\n queue is overflow!");
 	               
 	              	else
 	              	{
 	              		printf("enter the data to queue\n");
 	              		scanf("%d",&data);
 	              		enqueue(&q,data);
					   }
					   printf("sucessfully queued\n");
				
					   break;
		
		case 2:if(isunderflow(q)==1)
		         
		      	printf("\n queue is underflowed!");
		        	
				 
				 else
				 {
				 	data=dequeue(&q);
				 	printf("\n data dequeue \n");
				 }
				 break;
	 case 3:if(isunderflow(q)==1)
	           printf("\nunderflow!");
	           else
	           display(q);
	           break;
	           
	case 4:exit(0);
	       break;
 }

}while(ch>=1&&ch<=4);
 	
 }
