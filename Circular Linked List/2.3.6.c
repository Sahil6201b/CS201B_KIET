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

NODE insertAtBeginInCLL(NODE first, int x) {
	NODE newNode = createNodeInCLL();
	newNode->data = x;
		if(first == NULL){
		    newNode->next = newNode;   // point to itself
		    return newNode;
		}
	NODE temp = first;
	while(temp->next != first){
		temp = temp->next;
	}
	newNode->next = first;
	temp->next = newNode;
	first = newNode;
	return first;
}

NODE deleteAtBeginInCLL(NODE first) {
	if(first->next == first){
		printf("The deleted element from CLL : %d\n", first->data);
		free(first);
		first = NULL;
		return first;
	}
	NODE temp = first;
	while(temp->next != first){
		temp = temp->next;
	}
	temp->next = first->next;
	printf("The deleted element from CLL : %d\n",first->data);
	free(first);
	first = temp->next;
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
