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

NODE addNodesInCLL(NODE first, int x) {
	
	// Write your code here
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

void traverseListInCLL(NODE first) {
	
	// Write your code here
	NODE temp = first;
	while(temp->next != first){
		printf("%d --> ",temp->data);
		temp = temp->next;
	}
	printf("%d --> \n",temp->data);
}
