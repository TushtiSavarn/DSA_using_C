//size of a string 
#define max 20
struct stack
 {
 	char arr[max];
 	int top
 }s;
 void push(struct stack*p,char data)
  {
  	p->top=p->top+1;
  	p->arr[p->top]=data;
  }
 int size(struct stack s)
  {
  	int i,c=0;
  	for(i=0;i<=s.top;i++)
  	 c++;
  	return c; 
  }
 void main()
  {
  	int i,len;
  	char str[max];
  	s.top=-1;
  	printf("\nEnter string to find size\n");
  	gets(str);
  	for(i=0;i<strlen(str);i++)
  	 {
  	 	push(&s,str[i]);
	}
	len=size(s);
	printf("Size of string :%d",len);
  	
  	
   } 
