struct node {
	int data;
	struct node *next;
};
typedef struct node *NODE;

NODE createNode(int x) {
	NODE newNode = (NODE)malloc(sizeof(struct node));
	if(newNode == NULL){
		printf("Memory not allocated");
		exit(0);
	}
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}

NODE addNodes(NODE first, int x) {
	NODE newNode = createNode(x);
	if(first == NULL){
		first = newNode;
		return first;
	}
	NODE temp = first;
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = newNode;
	return first;
}

void traverseList(NODE first) {
	NODE temp = first;
	while(temp != NULL){
		printf("%d --> ",temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
}
