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

NODE insertAtTail(NODE head, int x) {
    NODE newNode = createNode(x);

    if (head == NULL) {
        return newNode;
    }

    NODE temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    return head;
}

void display(NODE head) {
    NODE temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int n, x, val;
    NODE head = NULL, temp, last = NULL;

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

    scanf("%d", &val);

    head = insertAtTail(head, val);

    display(head);

    return 0;
}
