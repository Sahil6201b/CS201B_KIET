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

int searchPosOfEleInCLL(NODE first, int key) {
	if (first == NULL)
        return 0;

    NODE temp = first;
    int pos = 1;

    do {
        if (temp->data == key)
            return pos;

        temp = temp->next;
        pos++;

    } while (temp != first);

    return 0;   // not found
}

void traverseListInCLL(NODE first) {
	NODE temp = first;
	do {
		printf("%d --> ", temp -> data);
		temp = temp -> next;
	} while (temp != first);
	printf("\n");
}
