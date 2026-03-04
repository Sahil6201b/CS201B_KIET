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

NODE insertAtEndInCLL(NODE first, int x) {
	NODE newNode = createNodeInCLL();
	newNode->data = x;
	if(first == NULL){
		// newNode->next = first;
		first = newNode;
		first->next = first;
		return first;
	}
	NODE temp = first;
	while(temp->next != first){
		temp = temp->next;
	}
	temp->next = newNode;
	newNode->next = first;
	return first;
}

NODE deleteAtEndInCLL(NODE first) {
	if(first->next == first){
		printf("The deleted item from CLL : %d\n", first->data);
		free(first);
		first = NULL;
		return first;
	}
	NODE temp = first;
	while(temp->next->next != first){
		temp = temp->next;
	}
	printf("The deleted item from CLL : %d\n", temp->next->data);
	free(temp->next);
	temp->next = first;
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
