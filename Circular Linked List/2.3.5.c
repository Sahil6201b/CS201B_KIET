struct node {
	int data;
	struct node *next;
};
typedef struct node *NODE;

NODE createNodeInCLL() {
	NODE temp;
	temp = (NODE) malloc(sizeof(struct node));
	temp -> next = NULL;
	return temp;
}

NODE insertAtPositionInCLL(NODE first, int pos, int x) {
	
	// Write your code here
	NODE newNode = createNodeInCLL();
    newNode->data = x;

    // Case 1: Empty List
    if (first == NULL) {
        if (pos == 1) {
            newNode->next = newNode;   // Make circular
            return newNode;
        } else {
            printf("No such position in CLL so insertion is not possible\n");
            free(newNode);
            return first;
        }
    }

    // Case 2: Insert at Beginning
    if (pos == 1) {

        NODE temp = first;

        // Go to last node
        while (temp->next != first) {
            temp = temp->next;
        }

        newNode->next = first;
        temp->next = newNode;
        first = newNode;

        return first;
    }

    // Case 3: Insert at Other Position
    NODE temp = first;
    int i = 1;

    while (i < pos - 1 && temp->next != first) {
        temp = temp->next;
        i++;
    }

    // If position is invalid
    if (i != pos - 1) {
        printf("No such position in CLL so insertion is not possible\n");
        free(newNode);
        return first;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    return first;
	
}

void traverseListInCLL(NODE first) {
	NODE temp = first;
	do {
		printf("%d --> ", temp -> data);
		temp = temp -> next;
	} while (temp != first);
	printf("\n");
}
