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

NODE reverseList(NODE head) {
    NODE prev = NULL;
    NODE curr = head;
    NODE next = NULL;

    while (curr != NULL) {
        next = curr->next;   // store next node
        curr->next = prev;   // reverse link
        prev = curr;         // move prev forward
        curr = next;         // move curr forward
    }

    return prev;   // new head
}

int main() {
    int n, x;
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

    // print original list
    display(head);

    // reverse list
    head = reverseList(head);

    // print reversed list
    display(head);

    return 0;
}
