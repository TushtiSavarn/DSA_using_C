#include<stdio.h>
#include<stdlib.h>
#include<process.h>
#define MAX_SIZE 5

// Structure to represent a dequeue
struct Dequeue {
    int arr[MAX_SIZE];
    int front;
    int rear;
};

// Function to initialize a dequeue
void initialize(struct Dequeue* dq) {
    dq->front = -1;
    dq->rear = -1;
}

// Function to check if the dequeue is empty
int isEmpty(struct Dequeue* dq) {
    return (dq->front == -1 && dq->rear == -1);
}

// Function to check if the dequeue is full
int isFull(struct Dequeue* dq) {
    return ((dq->rear + 1) % MAX_SIZE == dq->front);
}
// Function to add an element to the rear of the dequeue
void enqueueRear(struct Dequeue* dq, int data) {
    if (isFull(dq)) {
        printf("Dequeue is full. Cannot enqueue rear.\n");
        return;
    }
    if (isEmpty(dq)) {
        dq->front = dq->rear = 0;
    } else {
        dq->rear = (dq->rear + 1) % MAX_SIZE;
    }
    dq->arr[dq->rear] = data;
}

// Function to remove an element from the front of the dequeue
int dequeueFront(struct Dequeue* dq) {
    if (isEmpty(dq)) {
        printf("Dequeue is empty. Cannot dequeue front.\n");
        return -1; // Return a sentinel value to indicate failure
    }
    int data = dq->arr[dq->front];
    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1; // Dequeue becomes empty
    } else {
        dq->front = (dq->front + 1) % MAX_SIZE;
    }
    return data;
}

// Function to remove an element from the rear of the dequeue
int dequeueRear(struct Dequeue* dq) {
    if (isEmpty(dq)) {
        printf("Dequeue is empty. Cannot dequeue rear.\n");
        return -1; // Return a sentinel value to indicate failure
    }
    int data = dq->arr[dq->rear];
    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1; // Dequeue becomes empty
    } else {
        dq->rear = (dq->rear - 1 + MAX_SIZE) % MAX_SIZE;
    }
    return data;
}
 void display(struct Dequeue* dq)
  {
    if (isEmpty(dq)) {
        printf("Dequeue is empty.\n");
        return;
    }

    printf("Front-> ");
    int i = dq->front;

    // Loop through the dequeue and print elements
    while (i != dq->rear) {
        printf("%d \t", dq->arr[i]);
        i = (i + 1) % MAX_SIZE;
       }

    // Print the last element (or the only element if there's just one)
    printf("%d\t<-Rear", dq->arr[i]);
    
 }   


void main() 
{
	int ch,data;
    struct Dequeue dq;
    initialize(&dq);
    do
      {
      	printf("Menu\n");
       	printf("1 insertrear\n");
      	printf("2 deleterear\n");
      	printf("3 deletefront\n");
      	printf("4 dispaly\n");
      	printf("5 exit\n");
      	scanf("%d",&ch);
      	switch(ch)
      	{
      	
      		case 1:
			       printf("Enter the data to insert in rear\n");
				   scanf("%d",&data);
				   enqueueRear(&dq,data);
				   break;
			case 2:
			       data=dequeueRear(&dq);
				   printf("%d dequeued from rear\n",data);
				   break;
			case 3:
				   data=dequeueFront(&dq);
				   printf("%d dequeued from front\n",data);
				   break;
			case 4:
				   display(&dq);
				   break;
			case 5:
			       exit(0);	   	   	   
      			   
		  }
	  }
	  while(ch>=1&&ch<=5);
   
}
