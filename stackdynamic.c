#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
typedef struct node node;

node *top = NULL;

void push(int num)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = num;
    newnode->next = NULL;
    if (top == NULL)
    {
        top = newnode;
        return;
    }
    else
    {
        newnode->next = top;
        top = newnode;
    }
    printf("\nData inserted\n");
}

void pop()
{
    if (top == NULL)
    {
        printf("\nList is empty\n");
        return;
    }
    node *temp = top;
    top = top->next;
    printf("\ndeleting node with data %d\n", temp->data);
    free(temp);
}

void display()
{
    if (top == NULL)
    {
        printf("\nList is empty\n");
        return;
    }
    node *temp = top;
    while (temp != NULL)
    {
        printf("\n node with data %d", temp->data);
        temp = temp->next;
    }
}

int main()
{
    int ch, num;
    do
    {
        printf("\nMenu\n1Push\n2Pop\n3 Display\n4Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter data to insert: \n");
            scanf("%d", &num);
            push(num);
            break;
        case 2:
            pop();
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

