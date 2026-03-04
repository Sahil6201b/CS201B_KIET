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
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

NODE reverseK(NODE head, int k) {
    NODE curr = head;
    NODE prev = NULL;
    NODE next = NULL;
    int count = 0;

    // check if there are at least k nodes
    NODE temp = head;
    int nodes = 0;
    while (temp != NULL && nodes < k) {
        temp = temp->next;
        nodes++;
    }

    if (nodes < k)
        return head;

    // reverse first k nodes
    while (curr != NULL && count < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    if (next != NULL)
        head->next = reverseK(next, k);

    return prev;
}

int main() {
    int n, x, k;
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

    scanf("%d", &k);

    head = reverseK(head, k);

    display(head);

    return 0;
}
