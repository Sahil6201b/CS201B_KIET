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

int detectCycle(NODE head) {
    NODE slow = head;
    NODE fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return 1; // Cycle exists
        }
    }

    return 0; // No cycle
}

int main() {
    int n, x, cycle_start;
    NODE head = NULL, temp, last = NULL;
    NODE nodes[100];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        temp = createNode(x);
        nodes[i] = temp;

        if (head == NULL) {
            head = temp;
            last = temp;
        } else {
            last->next = temp;
            last = temp;
        }
    }

    scanf("%d", &cycle_start);

    if (cycle_start != 0) {
    last->next = head;   // create a cycle
}

    if (detectCycle(head))
        printf("Given List has cycle: Yes\n");
    else
        printf("Given List has cycle: No\n");

    return 0;
}
