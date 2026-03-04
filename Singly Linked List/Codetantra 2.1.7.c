struct node {
	int data;
	struct node *next;
};
typedef struct node *NODE;

NODE createNode() {
	NODE temp;
	temp = (NODE) malloc(sizeof(struct node));
	temp -> next = NULL;
	return temp;
}

NODE insertAtPosition(NODE first, int pos, int x) {
	
   // Write your code here
	NODE newNode = createNode();
    newNode->data = x;

    // Case 1: Insert at position 1 (always allowed)
    if (pos == 1) {
        newNode->next = first;
        return newNode;
    }

    // If list is empty and pos > 1
    if (first == NULL) {
        printf("No such position in SLL so insertion is not possible\n");
        free(newNode);
        return first;
    }

    NODE temp = first;
    int count = 1;

    // Move to (pos-1)th node
    while (temp != NULL && count < pos - 1) {
        temp = temp->next;
        count++;
    }

    // If position does not exist
    if (temp == NULL) {
        printf("No such position in SLL so insertion is not possible\n");
        free(newNode);
        return first;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    return first;
}

void traverseList(NODE first) {
	
	// Write your code here
	NODE temp = first;
	while (temp != NULL) {
		printf("%d --> ",temp -> data);
		temp = temp -> next;
	}
	printf("NULL\n");
}
