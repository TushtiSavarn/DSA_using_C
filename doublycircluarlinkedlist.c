#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
    struct node* prev;
};

typedef struct node node;

node* head = NULL;

int count() {
    int c = 0;
    node* cur = head;

    if (cur == NULL) {
        return 0;
    }

    do {
        c++;
        cur = cur->next;
    } while (cur != head);

    return c;
}

void display() {
    node* cur = head;

    if (cur == NULL) {
        printf("\nList is empty\n");
        return;
    }

    do {
        printf("%d\t", cur->data);
        cur = cur->next;
    } while (cur != head);
    printf("\n");
}

void addbefore(int num) {
    int n;
    node* cur, * pre;
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = num;

    cur = head;
    if (head == NULL) {
        head = newnode;
        head->next = head;
        head->prev = head;
        return;
    }

    printf("\nEnter the node before which you want to insert: ");
    scanf("%d", &n);

    if (cur->data == n) {
        newnode->next = head;
        newnode->prev = head->prev;
        head->prev->next = newnode;
        head->prev = newnode;
        head = newnode;
        return;
    }

    do {
        if (cur->data == n) {
            pre = cur->prev;
            pre->next = newnode;
            newnode->prev = pre;
            newnode->next = cur;
            cur->prev = newnode;
            return;
        }
        cur = cur->next;
    } while (cur != head);

    printf("\nData not found\n");
    free(newnode); // Free the allocated memory for newnode
}

void addafter(int num) {
    int n;
    node* cur, * newnode;
    newnode = (node*)malloc(sizeof(node));
    newnode->data = num;

    if (head == NULL) {
        head = newnode;
        head->next = head;
        head->prev = head;
        return;
    } else {
        printf("\nEnter the node after which you want to insert: ");
        scanf("%d", &n);
        cur = head;

        do {
            if (cur->data == n) {
                newnode->next = cur->next;
                newnode->prev = cur;
                cur->next->prev = newnode;
                cur->next = newnode;
                return;
            }
            cur = cur->next;
        } while (cur != head);

        printf("%d not found\n", n);
        free(newnode); // Free the allocated memory for newnode
    }
}

void delfirst() {
    if (head == NULL) {
        printf("\nList is empty\n");
        return;
    }

    node* temp = head;
    head = head->next;
    if (head == temp) {
        head = NULL; // List is now empty
    } else {
        head->prev = temp->prev;
        temp->prev->next = head;
    }

    printf("\nFirst node with data %d deleted\n", temp->data);
    free(temp);
}

void delast() {
    if (head == NULL) {
        printf("\nList is empty\n");
        return;
    }

    node* cur = head->prev; // Last node
    if (cur == head) {
        head = NULL; // List is now empty
    } else {
        cur->prev->next = head;
        head->prev = cur->prev;
    }

    printf("\nLast node with data %d deleted\n", cur->data);
    free(cur);
}

void delmiddle(int loc) {
    int i;
    if (head == NULL) {
        printf("\nList is empty\n");
        return;
    }
    if (loc < 1 || loc > count()) {
        printf("\nInvalid location\n");
        return;
    }
    node* temp;
    node* cur = head;

    if (loc == 1) {
        temp = head;
        head = head->next;
        head->prev = temp->prev;
        temp->prev->next = head;
    } else {
        for (i = 1; i < loc; i++) {
            cur = cur->next;
        }
        temp = cur;
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
    }

    printf("\nNode at position %d with data %d deleted\n", loc, temp->data);
    free(temp);
}

void reverse() {
    node* cur = head;
    node* temp = NULL;

    if (cur == NULL) {
        return; // List is empty, nothing to reverse
    }

    do {
        temp = cur->prev;
        cur->prev = cur->next;
        cur->next = temp;
        cur = cur->prev;
    } while (cur != head);

    head = head->prev;
}

int main() {
    int ch, num, loc;
    do {
        printf("\nMenu\n1 Add before\n2 Add after\n3 Count\n4 Display\n5 Delete first\n6 Delete last\n7 Delete middle\n8 Reverse\n9 Exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("\nEnter data to insert: ");
                scanf("%d", &num);
                addbefore(num);
                break;
            case 2:
                printf("\nEnter data to insert: ");
                scanf("%d", &num);
                addafter(num);
                break;
            case 3:
                printf("Number of nodes is %d\n", count());
                break;
            case 4:
                display();
                break;
            case 5:
                delfirst();
                break;
            case 6:
                delast();
                break;
            case 7:
                printf("\nEnter position of node to delete: ");
                scanf("%d", &loc);
                delmiddle(loc);
                break;
            case 8:
                reverse();
                break;
            case 9:
                exit(0);
            default:
                printf("\nInvalid choice\n");
                break;
        }
    } while (1);

    return 0;
}

