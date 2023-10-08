#include <stdio.h>
#include <stdlib.h> // Include stdlib.h for malloc and exit functions
struct node {
    int data;
    struct node* next;
};
typedef struct node node;
node* head = NULL; // Initialize the head pointer
int count()
 {
    int c = 0;
    node* cur = head;
    while (cur != NULL) 
	{
        c++;
        cur = cur->next;
    }
    return c;
}
void display()
 {
    node* cur = head;
    if (cur == NULL) 
	{
        printf("\nList is empty");
    } else 
	{
        while (cur != NULL) 
		{
            printf("%d\t", cur->data);
            cur = cur->next;
        }
    }
}
void addbeg(int num) 
{
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = num;
    newnode->next = head;
    head = newnode;
}
void addlast(int num) 
{
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = num;
    newnode->next = NULL;
    if (head == NULL)
	 {
        head = newnode;
        return;
    }
    node* cur = head;
    while (cur->next != NULL) 
	{
        cur = cur->next;
    }
    cur->next = newnode;
}
void addbet(int loc, int num) 
{
    int i;
    if (loc < 1 || loc > count() + 1) 
	{
        printf("\nInvalid location\n");
        return;
    }
    if (loc == 1)
	 {
        addbeg(num);
        return;
    }
    if (loc == count() + 1)
	 {
        addlast(num);
        return;
    }
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = num;
    newnode->next = NULL;
    node* cur = head;
    for (i = 1; i < loc - 1; i++)
	 {
        cur = cur->next;
    }
    newnode->next = cur->next;
    cur->next = newnode;
}
void delfirst() 
{
    if (head == NULL)
	 {
        printf("\nList is empty\n");
        return;
    }
    node* temp = head;
    head = head->next;
    printf("\nFirst node with data %d", temp->data);
    free(temp);
}
void delast() 
{
    if (head == NULL)
	 {
        printf("\nList is empty\n");
        return;
    }
    node* cur = head;
    node* pre = NULL;
    while (cur->next != NULL) 
	{
        pre = cur;
        cur = cur->next;
    }
    if (pre == NULL) 
	{
        head = NULL; // If there was only one element in the list
    } 
	else 
	{
        pre->next = NULL;
    }
    printf("\nData deleted %d", cur->data);
    free(cur);
}
void delmiddle(int loc)
 {
    int i;
    if (head == NULL) 
	{
        printf("\nList is empty\n");
        return;
    }
    if (loc < 1 || loc > count()) 
	{
        printf("\nInvalid location\n");
        return;
    }
    node* temp;
    node* cur = head;
    if (loc == 1) 
	{
        head = head->next;
        temp = cur;
    } 
	else 
	{
        for (i = 1; i < loc - 1; i++)
		 {
            cur = cur->next;
        }

        temp = cur->next;
        cur->next = cur->next->next;
    }
    printf("\n%d data deleted", temp->data);
    free(temp);
}
int main()
 {
    int ch, num, loc;
    do {
        printf("\nMenu\n1 Add beginning\n2 Add middle\n3 Add last\n4 Count\n5 Display\n6 Delete first\n7 Delete last\n8 Delete middle\n9 Exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("\nEnter data to insert: ");
                scanf("%d", &num);
                addbeg(num);
                break;
            case 2:
                printf("\nEnter position of node to insert: ");
                scanf("%d", &loc);
                printf("\nEnter data to insert: ");
                scanf("%d", &num);
                addbet(loc, num);
                break;
            case 3:
                printf("\nEnter data to insert: ");
                scanf("%d", &num);
                addlast(num);
                break;
            case 4:
                printf("Number of nodes is %d\n", count());
                break;
            case 5:
                display();
                break;
            case 6:
                delfirst();
                break;
            case 7:
                delast();
                break;
            case 8:
                printf("\nEnter position of node to delete: ");
                scanf("%d", &loc);
                delmiddle(loc);
                break;
            case 9:
                exit(0);
                break;
            default:
                printf("\nInvalid choice\n");
                break;
        }
    } while (ch >= 1 && ch <= 9);

    return 0;
}

