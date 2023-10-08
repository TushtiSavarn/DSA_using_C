#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};
typedef struct node node;

node *front = NULL;
node *rear = NULL;
node *temp;

void enqueue(int num) 
{
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = num;
    newnode->next = NULL;

    if (front == NULL && rear == NULL)
    {
        front = rear = newnode;
        return;
    }

    rear->next = newnode;
    rear = newnode;
}

void dequeue()
{
    if (front == NULL)
    {
        printf("\nQueue is empty\n");
        return;
    }

    temp = front;

    if (front == rear)
    {
        front = rear = NULL;
    }
    else
    {
        front = front->next;
    }

    printf("%d data deleted\n", temp->data);
    free(temp);
}

void display()
{
    if (front == NULL)
    {
        printf("\nQueue is empty\n");
        return;
    }

    node* temp = front;
    while (temp != NULL)
    {
        printf("\nNode with data %d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int ch, num;
    do
    {
        printf("\nMenu\n1 Enqueue\n2 Dequeue\n3 Display\n4 Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter data to enqueue: ");
            scanf("%d", &num);
            enqueue(num);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("\nExiting the program\n");
            exit(0);
        }
    } while (ch >= 1 && ch <= 4);

    return 0;
}

