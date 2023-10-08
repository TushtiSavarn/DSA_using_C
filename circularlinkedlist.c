#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

typedef struct node node;
node* head = NULL;

int count() {
    int c = 0;
    node* cur = head;
    
    if (cur == NULL) {
        return 0; // List is empty
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
        return;
    }
    
    printf("\nEnter the node before which you want to insert: ");
    scanf("%d", &n);
    
    if (cur->data == n) {
        newnode->next = head;
        while (cur->next != head) {
            cur = cur->next;
        }
        cur->next = newnode;
        head = newnode;
        return;
    }
    
    do {
        pre = cur;
        cur = cur->next;
        if (cur->data == n) {
            pre->next = newnode;
            newnode->next = cur;
            return;
        }
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
        return;
    } else {
        printf("\nEnter the node after which you want to insert: ");
        scanf("%d", &n);
        cur = head;
        
        do {
            if (cur->data == n) {
                newnode->next = cur->next;
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
    
    if (temp->next == head) {
        head = NULL; // If there was only one element in the list
    } else {
        node* cur = head;
        while (cur->next != head) {
            cur = cur->next;
        }
        head = head->next;
        cur->next = head;
    }
    
    printf("\nFirst node with data %d deleted\n", temp->data);
    free(temp);
}

void delast() {
    if (head == NULL) {
        printf("\nList is empty\n");
        return;
    }
    
    node* cur = head;
    node* pre = NULL;
    
    if (cur->next == head) {
        head = NULL; // If there was only one element in the list
    } else {
        while (cur->next != head) {
            pre = cur;
            cur = cur->next;
        }
        pre->next = head;
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
        head = head->next;
        temp = cur;
    } else {
        for (i = 1; i < loc - 1; i++) {
            cur = cur->next;
        }
        temp = cur->next;
        cur->next = cur->next->next;
    }
    
    printf("\nNode at position %d with data %d deleted\n", loc, temp->data);
    free(temp);
}

void reverse() {
    if (head == NULL) {
        printf("\nList is empty\n");
        return;
    }
    
    node* cur = head;
    node* left = NULL;
    node* right = NULL;
    
    do {
        right = cur->next;
        cur->next = left;
        left = cur;
        cur = right;
    } while (cur != head);
    
    head->next = left;
    head = left;
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

