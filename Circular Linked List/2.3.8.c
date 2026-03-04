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

NODE deleteAtPositionInCLL(NODE first, int pos) {
	if (first->next == first && pos == 1) {
        printf("The deleted element from CLL : %d\n", first->data);
        free(first);
        return NULL;
    }
	if(pos == 1){
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

	int i = 1;
NODE temp = first;

while(i < pos-1 && temp->next != first){
    temp = temp->next;
    i++;
}

//  POSITION CHECK
if(i != pos-1 || temp->next == first){
    printf("No such position in CLL so deletion is not possible\n");
    return first;
}

NODE delNode = temp->next;
printf("The deleted element from CLL : %d\n", delNode->data);
temp->next = delNode->next;
free(delNode);

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
