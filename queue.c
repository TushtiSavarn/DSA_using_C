#include<stdio.h>
#include<process.h>
#define max 20
struct queue
 {
 	int arr[max];
 	int front,rear;
 };
 typedef struct queue queue;
 void enqueue(queue*pq,int data)
     {
     	if(pq->rear==-1)//1st element insert
     	 {
     	 	pq->front++;
     	 	pq->rear++;
     	 	
     	 }
     	else
     	 {
     	 	pq->rear++;// some elements are already here
     	 	    	 	
		 }
		  pq->arr[pq->rear]=data;
	     
	 }
	int dequeue(queue*pq)
	 {
	 	int data;
	 	if(pq->rear==pq->front)//deleting 1st element
	 	 {
	 	 	data=pq->arr[pq->front];
	 	 	pq->front=pq->rear=-1;
		  }
		else
		 {
		 	data=pq->arr[pq->front];
		 	pq->front++;
		   }
		  return data;   
	  } 
	 void display(queue q)
	  {
	  	int i;
	  	printf("\nFront->");
	  	for(i=q.front;i<=q.rear;i++)
	  	 {
	  	 	printf("\t%d",q.arr[i]);
		  }
		 printf("<-Rear"); 
	   } 
	  void lenght(queue q)
	   {
	   	int i,c=0;
		for(i=q.front;i<=q.rear;i++)
		 c++;
		printf("\nLenght=%d",c);     
      }
 void main() 
  {
  	int ch,data;
  	queue q;
  	q.rear=-1;
	q.front=-1;
  	int isoverflow(queue q)
  	 {
  	 	if(q.rear=max-1)
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
		 {
		 	return 0;
		}   
	}
	do
	 {
	 	printf("\nMenu:-");
	 	printf("\n1-enqueue");
	 	printf("\n2-dequeue");
	 	printf("\n3-dispaly");
	 	printf("\n4-lenght");
	 	printf("\n5-exit");
	 	scanf("%d",&ch);
	    switch(ch) 
		{
			case 1:
				   if(isoverflow(q)==1)
				    {
				    	printf("\nOverflow");
					}
					else
					 {
					 	printf("\nEnter data to enqueue");
					 	scanf("%d",&data);
					 	enqueue(&q,data);
					 }
					break;
			case 2:
			       if(isunderflow(q)==1)
				    {
				    	printf("\nUnderflow");
					 }
					else
					 {
					 	data=dequeue(&q);
					 	printf("\nData dequeue");
					  }
					 break;
			case 3:
			       display(q);
				   break;
			case 4:
			       lenght(q);
				   break;
			case 5:
			       exit(0);	   	   		   		 
 		}
    } while(ch>=1&&ch<=5);
    
}
