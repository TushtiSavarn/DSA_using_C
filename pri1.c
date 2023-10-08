#include<stdio.h>
#include<stdlib.h>
#include<process.h>
#define size 5

int queue[size], pri[size];
int front = -1, rear = -1;

void shift(int a)
{
    int i;
    for (i = rear; i > a; i--)
    {
        queue[i] = queue[i - 1];
        pri[i] = pri[i - 1];
    }
}

void sort(int data, int p)
{
    int f = front, r = rear;
    if (p < pri[f]) // Highest priority
    {
        shift(f);
        queue[f] = data;
        pri[f] = p;
    }
    else if (p > pri[r]) // Last priority
    {
        queue[r + 1] = data;
        pri[r + 1] = p;
        rear++;
    }
    else // Middle priority
    {
        while (p >= pri[f])
            f++;
        shift(f);
        queue[f] = data;
        pri[f] = p;
        rear++;
    }
}

void enqueue(int data, int p)
{
    if (rear == size - 1)
    {
        printf("Queue is overflow\n");
    }
    else
    {
        if (front == -1)
        {
            front = 0;
            rear = 0;
            queue[rear] = data;
            pri[rear] = p;
        }
        else
        {
            sort(data, p);
        }
    }
}

int dequeue()
{
    int i = front + 1, tt = front, data;
    while (i <= rear)
    {
        if (pri[tt] > pri[i])
            tt = i;
        i++;
    }
    data = queue[tt];
    shift(tt);
    rear--;

    if (front > rear)
    {
        front = -1;
        rear = -1;
    }
    return data;
}

void display()
{
    int i;
    printf("Front -> ");
    for (i = front; i <= rear; i++)
        printf("%d\t", queue[i]);
    printf("<- Rear\n");
    printf("\nPriority Front --> ");
    for (i = front; i <= rear; i++)
        printf("%d\t", pri[i]);
    printf("<- Priority Rear\n");
}

int isunderflow()
{
    if (front == -1)
        return 1;
    else
        return 0;
}

int isoverflow()
{
    if (rear == size - 1)
        return 1;
    else
        return 0;
}

int main()
{
    int data, ch, p;
    front = -1;
    rear = -1;
    do
    {
        printf("\nMenu\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            if (isoverflow() == 1)
                printf("Queue is overflow\n");
            else
            {
                printf("Enter the data: ");
                scanf("%d", &data);
                printf("Enter the priority: ");
                scanf("%d", &p);
                enqueue(data, p);
            }
            break;
        case 2:
            if (isunderflow() == 1)
                printf("Queue underflow, can't dequeue\n");
            else
            {
                data = dequeue();
                printf("%d dequeued\n", data);
            }
            break;
        case 3:
            if (isunderflow() == 1)
                printf("Queue is empty\n");
            else
                display();
            break;
        case 4:
            exit(0);
        }
    } while (ch >= 1 && ch <= 4);
    return 0;
}

