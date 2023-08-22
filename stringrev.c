//reversal of string
#define size 20
struct stack 
 {
 	char arr[size];
 	int top;
 };
  char pop(struct stack*p)
 {
 	char data;
 	data=p->arr[p->top];
 	p->top--;
 	return data;
 }
 void push( struct stack*p,char data)
 {
     p->top=p->top+1;
	 p->arr[p->top]=data;	
 }
 void main() 
 {
 	int i,l;
 	char str[size],c;
 	struct stack s;
 	s.top=-1;
 	printf("\nEnter string to reverse\n");
 	gets(str);
 	l=strlen(str);
 	for(i=0;i<l;i++)
	 {
	 	push(&s,str[i]);
	 }
	for(i=0;i<l;i++)
	{
		str[i]=pop(&s);
	} 
	printf("\nReversed string:-%s",str);
 	
 }
