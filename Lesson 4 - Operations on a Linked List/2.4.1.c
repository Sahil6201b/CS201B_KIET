#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};

// Type Content here...
typedef struct node *NODE;

NODE first = NULL;

void insert() {
    int x;
    printf("Element: ");
    scanf("%d", &x);

    NODE temp = (NODE)malloc(sizeof(struct node));
    temp->value = x;
    temp->next = NULL;

    if (first == NULL) {
        first = temp;
    } 
    else {
        NODE q = first;
        while (q->next != NULL) {
            q = q->next;
        }
        q->next = temp;
    }
}

void delete_node() {
    int pos, i;
    printf("Position: ");
    scanf("%d", &pos);

    if (first == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    if (pos < 1) {
        printf("Invalid position\n");
        return;
    }

    NODE temp = first;

    if (pos == 1) {
        first = first->next;
        free(temp);
        printf("Deleted successfully\n");
        return;
    }

    NODE prev = NULL;

    for (i = 1; i < pos; i++) {
        prev = temp;
        temp = temp->next;

        if (temp == NULL) {
            printf("Invalid position\n");
            return;
        }
    }

    prev->next = temp->next;
    free(temp);
    printf("Deleted successfully\n");
}

void display() {
    if (first == NULL) {
        printf("The list is empty\n");
        return;
    }

    NODE temp = first;
    printf("Elements of linked list: ");

    while (temp != NULL) {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

void count() {
    int c = 0;
    NODE temp = first;

    while (temp != NULL) {
        c++;
        temp = temp->next;
    }

    printf("No of elements: %d\n", c);
}


int main() {
    int option = 0;
    while (1) {
        printf("1.Insert 2.Delete 3.Display 4.Count 5.Exit\n");
        printf("choice: ");
        scanf("%d", &option);
        switch (option) {
            case 1:
                insert();
                break;
            case 2:
                delete_node();
                break;
            case 3:
                display();
                break;
            case 4:
                count(); 
                break;
            case 5:
                return 0;  // Exit the program
            default:
                printf("Enter options from 1 to 5\n");
                break;
        }
    }
    return 0;
}
