// Type Content here...
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node* NODE;

NODE createNode(int x) {
    NODE temp = (NODE)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = NULL;
    return temp;
}

void display(NODE head) {
    NODE temp = head;
    while (temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

NODE insertMiddle(NODE head, int v) {
    
    if (head == NULL) {
        return createNode(v);
    }

    int count = 0;
    NODE temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    int mid = count / 2;

    temp = head;
    for (int i = 1; i < mid; i++) {
        temp = temp->next;
    }

    NODE newNode = createNode(v);

    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

int main() {
    int n, x, v;
    NODE head = NULL, last = NULL, temp;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        temp = createNode(x);

        if (head == NULL) {
            head = temp;
            last = temp;
        } else {
            last->next = temp;
            last = temp;
        }
    }

    scanf("%d", &v);

    display(head);

    head = insertMiddle(head, v);

    display(head);

    return 0;
}
