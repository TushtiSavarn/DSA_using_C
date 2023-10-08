#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

struct Dequeue {
    int arr[MAX_SIZE];
    int front;
    int rear;
};

// Function to check if the dequeue is empty
int isEmpty(struct Dequeue* dq) {
    return (dq->front == -1 && dq->rear == -1);
}

// Function to check if the dequeue is full
int isFull(struct Dequeue* dq) {
    return ((dq->rear + 1) % MAX_SIZE == dq->front);
}

// Function to add an element to the front of the dequeue
void enqueueFront(struct Dequeue* dq, int data) {
    if (isFull(dq)) {
        printf("Dequeue is full. Cannot enqueue front.\n");
        return;
    }
    if (isEmpty(dq)) {
        dq->front = dq->rear = 0;
    } else {
        dq->front = (dq->front - 1 + MAX_SIZE) % MAX_SIZE;
    }
    dq->arr[dq->front] = data;
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

// Function to display the dequeue
void display(struct Dequeue* dq) {
    if (isEmpty(dq)) {
        printf("Dequeue is empty.\n");
        return;
    }

    printf("Front -> ");
    int i = dq->front;

    while (i != dq->rear) {
        printf("%d -> ", dq->arr[i]);
        i = (i + 1) % MAX_SIZE;
    }

    printf("%d -> Rear\n", dq->arr[i]);
}

int main() {
    struct Dequeue dq;
    dq.front = -1;
    dq.rear = -1;

    int choice, data;

    do {
        printf("Menu\n");
        printf("1. Enqueue Front\n");
        printf("2. Enqueue Rear\n");
        printf("3. Dequeue Front\n");
        printf("4. Dequeue Rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to enqueue at the front: ");
                scanf("%d", &data);
                enqueueFront(&dq, data);
                break;
            case 2:
                printf("Enter data to enqueue at the rear: ");
                scanf("%d", &data);
                enqueueRear(&dq, data);
                break;
            case 3:
                data = dequeueFront(&dq);
                if (data != -1)
                    printf("Dequeued from the front: %d\n", data);
                break;
            case 4:
                data = dequeueRear(&dq);
                if (data != -1)
                    printf("Dequeued from the rear: %d\n", data);
                break;
            case 5:
                display(&dq);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (1);

    return 0;
}

