#include <stdio.h>
#include <stdlib.h>

int pq[5][5];
int f[5], r[5];

int isOverflow(int p) {
    if (r[p] == 4) // Check if the queue is full
        return 1;
    else
        return 0;
}

void enqueue(int p, int data) {
    if (p >= 0 && p < 5) { // Check if p is within a valid range
        if (isOverflow(p) == 1)
            printf("\nPriority queue with priority %d is full\n", p);
        else {
            if (r[p] == -1) {
                r[p] = f[p] = 0;
                pq[p][r[p]] = data;
            } else {
                r[p]++;
                pq[p][r[p]] = data;
            }
        }
    } else {
        printf("\nInvalid priority\n");
    }
}

int dequeue() {
    int highestPriority = 4;
    while (highestPriority >= 0 && f[highestPriority] == -1)
        highestPriority--;

    if (highestPriority >= 0) {
        int data = pq[highestPriority][f[highestPriority]];
        if (f[highestPriority] == r[highestPriority])
            f[highestPriority] = r[highestPriority] = -1;
        else
            f[highestPriority]++;

        return data;
    } else {
        printf("\nPriority queue is empty\n");
        return -1; // Return a sentinel value for empty queue
    }
}

void display() {
    int i, j;
    printf("\nPriority Queue:\n");
    for (i = 4; i >= 0; i--) {
        if (f[i] != -1) {
            printf("Priority %d: ", i);
            for (j = f[i]; j <= r[i]; j++) {
                printf("%d ", pq[i][j]);
            }
            printf("\n");
        }
    }
}

int main() {
    int i, ch, p, data;
    for (i = 0; i < 5; i++)
        r[i] = f[i] = -1;

    do {
        printf("\nMenu\n1 enqueue\n2 dequeue\n3 display\n4 exit");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("\nEnter priority: ");
                scanf("%d", &p);
                printf("\nEnter the data: ");
                scanf("%d", &data);
                enqueue(p, data);
                break;
            case 2:
                data = dequeue();
                if (data != -1)
                    printf("Data dequeued: %d\n", data);
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
        }
    } while (1);

    return 0;
}

