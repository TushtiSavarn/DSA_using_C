//poly addtions
#include<stdio.h>
#include<stdlib.h>
struct node
 {
 	int coef;
 	int exp;
 	struct node*next;
 };
 typedef struct node node;
 node* createpoly( node*head,int c,int e)
  {
    node*pre,*cur;
    node*newnode;
    newnode->exp=e;
	newnode->coef=c;
	if(head==NULL)
	 {
	 	newnode->next=NULL;
	 	return newnode;
	 }	
	pre=cur=head;
	while(cur!=NULL&&cur->exp>e)
	 {
	 	pre=cur;
	 	cur=cur->next;
	  } 
	if(cur=head)
	 {
	 	newnode->next=cur;
	 	return(newnode);
     }
 	else if(cur==NULL)
	 {
	 	pre->next=newnode;
	 	newnode->next=NULL;
     }   
    else
	 {
	 	newnode->next=cur;
	 	pre->next=newnode;
	  } 
	return head;  
  }
  node*polyadd(node*p1head,node*p2head)
   {
   	p3head=NULL;
   	*p1,*p2;
   	int sumcoef;
   	p1=p1head;
   	p2=p2head;
   	while(p1!=NULL&&p2!=NULL)
   	 {
   	 	if(p1->exp>p2->exp)
   	 	 {
   	 	  p3head=append(p3head,p1->coef,p1->exp);
   	 	  p1=p1->next;
		 }
		else if( p1->exp<p2->exp)
		 {
		 	p3head=append(p3head,p2->cef,p2->exp)
		 }
		else
		 {
		 	sumcoef=(p1->coef)+(p2->coef);
		 	if(sumcoef!=0)
		 	 {
		 	 	p3head=append(p3head,sumcoef,p1->exp);
		 	 	p1=p1->next;
		 	 	p2=p2->next;
			  }
	     }
	    }
			while(p!=NULL)
			 {
			 	p3head=append(p3head,p1->coef,p1->exp)
			 	p1=p1->next;
			   }  
			while(p2!=NULL)
			 {
			 	p3head=append(p3head,p2->coef,p2->exp);
			 	p2=p2->next;
			 }   
			return p3head; 
		   }  
   }
  node*append(node*head,int c,int e);
   {
   	newnode->coef=c;
   	newnode->exp=e;
   	if(head==NULL)
   	 {
   	 	newnode->next=NULL;
   	 	return newnode; 	
     }
    node*cur=head;
	while(cur->next!=NULL)
	 {
	 	cur=cur->next;
	 	cur=next=newnode;
	 	newnode->next=NULL;
	  } 
	} 
	void display(node*head)
	 {
	 	node*temp=head;
	 	if(temp==NULL)
	 	 {
	 	 	printf("\nEmpty");
		  }
		else
		 {
		 	printf("%dx^%d",temp->coef,temp->exp);
		 	temp=temp->next;
		 	while(temp!=NULL)
		 	 {
		 	 	if(temp->coef<0)
		 	 	 {
		 	 	 	printf("-%dx^%d",-1*temp->coef,temp->exp);
				   }
				else
				 {
				 	printf("+%dx^%d",temp->coef,temp->exp);
					} 
			 temp->next;	  
			  }
		   }  
	 }
	void main()
	 {
	 	int c,e,n,i;
	 	node*head1,*head2,*head3;
	 	head1=head2=NULL;
	 	printf("\nEnter the no of terms of polynomials ");
	 	scanf("%d",&n);
	 	printf("Enter the polynomial");
	 	for(i=0;i<n;i++)
	 	 {
	 	 	printf("\nEnter coefficient & exponenet of 1st polynomial");
	 	 	scanf("%d%d",&c,&e);
	 	 	head1=createpoly(head1,c,e);
		  }
	 	head2=createpoly(head2,c,e);
	  
    	head3=polyadd(head1,head2);
	    printf("\npolynomial 1\t");
	    display(head1);
	    printf("\npolynomial 2\t");
	    display(head2);
	    printf("\npolynomial sum =\t");
	    display(head3);
	 }
	  
