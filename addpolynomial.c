#include <stdio.h>
#include <stdlib.h>

struct node {
    int coef, exp;
    struct node *next;
};

typedef struct node Node;

Node *createpoly(Node *head, int c, int e) {
    Node *newnode, *prev, *curr;
    newnode = (Node *)malloc(sizeof(Node));
    newnode->coef = c;
    newnode->exp = e;
    newnode->next = NULL;

    if (head == NULL) {
        return newnode;
    }

    prev = NULL;
    curr = head;

    while (curr != NULL && curr->exp > e) {
        prev = curr;
        curr = curr->next;
    }

    if (prev == NULL) {
        newnode->next = head;
        return newnode;
    } else {
        prev->next = newnode;
        newnode->next = curr;
    }

    return head;
}

Node *append(Node *head, int c, int e) {
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->coef = c;
    newnode->exp = e;
    newnode->next = NULL;

    if (head == NULL) {
        return newnode;
    }

    Node *cur = head;
    while (cur->next != NULL) {
        cur = cur->next;
    }

    cur->next = newnode;
    return head;
}

Node *polyaddition(Node *p1head, Node *p2head) {
    Node *p1 = p1head, *p2 = p2head, *p3head = NULL;

    while (p1 != NULL && p2 != NULL) {
        if (p1->exp > p2->exp) {
            p3head = append(p3head, p1->coef, p1->exp);
            p1 = p1->next;
        } else if (p1->exp < p2->exp) {
            p3head = append(p3head, p2->coef, p2->exp);
            p2 = p2->next;
        } else {
            int sumcoef = p1->coef + p2->coef;
            if (sumcoef != 0) {
                p3head = append(p3head, sumcoef, p1->exp);
            }
            p1 = p1->next;
            p2 = p2->next;
        }
    }

    while (p1 != NULL) {
        p3head = append(p3head, p1->coef, p1->exp);
        p1 = p1->next;
    }

    while (p2 != NULL) {
        p3head = append(p3head, p2->coef, p2->exp);
        p2 = p2->next;
    }

    return p3head;
}

void display(Node *head) {
    Node *cur = head;

    if (cur == NULL) {
        printf("\nEmpty polynomial.");
    } else {
        printf("%dx^%d", cur->coef, cur->exp);
        cur = cur->next;

        while (cur != NULL) {
            if (cur->coef < 0) {
                printf("%dx^%d", cur->coef, cur->exp);
            } else {
                printf("+%dx^%d", cur->coef, cur->exp);
            }
            cur = cur->next;
        }
    }
}

int main() {
    int c, e, n, i;
    Node *head1 = NULL, *head2 = NULL, *head3 = NULL;

    printf("Enter the number of terms for polynomial 1: ");
    scanf("%d", &n);

    printf("Enter the coefficients and exponents for polynomial 1:\n");
    for (i = 0; i < n; i++) {
        printf("Enter coefficient and exponent: ");
        scanf("%d%d", &c, &e);
        head1 = createpoly(head1, c, e);
    }

    printf("Enter the number of terms for polynomial 2: ");
    scanf("%d", &n);

    printf("Enter the coefficients and exponents for polynomial 2:\n");
    for (i = 0; i < n; i++) {
        printf("Enter coefficient and exponent: ");
        scanf("%d%d", &c, &e);
        head2 = createpoly(head2, c, e);
    }

    head3 = polyaddition(head1, head2);

    printf("\nThe polynomial 1 is: ");
    display(head1);

    printf("\nThe polynomial 2 is: ");
    display(head2);

    printf("\nThe polynomial 3 (sum of polynomial 1 and 2) is: ");
    display(head3);

    return 0;
}

