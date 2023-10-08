//priority 3rd approach
#include<stdio.h>
#include<process.h>
#define size 10
int pq[5][10];
int front[5];
int rear[5];
void main()
 {
 	int i,ch,p,data;
 	for(i=0;i<5;i++)
 	 {
 	 	rear[i]=front[i]=-1;
	  }
	int isoverflow(int p)
	 {
	 	int index=p-1;
	 	if(rear[index]==size-1)
	 	 return 1;
	 	else 
		 return 0;
		 
	   } 
	int isunderflow(int p)
	 {
	 	if(front[p-1]==-1)
	 	 return 1;
	 	else
		 return 0; 
		 }    
	void enqueue(int p,int data)
	 {
	 	int r;
	 	if(rear[p-1]==-1)
	 	 rear[p-1]=front[p-1]=0;
	 	else
		  rear[p-1]=rear[p-1]+1;
		  r=rear[p-1];
		  pq[p-1][r]=data;
		  }	 
	int dequeue()
	 {
		int i,data,f;
		for(i=0;i<=4;i++)
		 {
		 	f=front[i];
		 	if(f!=-1)
		 }
	}	  
 }

