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

int countInCLL(NODE first) {
	if(first == NULL)
        return 0;
	int count = 0;
	NODE temp = first;
	do {
        count++;
        temp = temp->next;
    } while(temp != first);

    return count;
}

void traverseListInCLL(NODE first) {
	NODE temp = first;
	do {
		printf("%d --> ", temp -> data);
		temp = temp -> next;
	} while (temp != first);
	printf("\n");
}
