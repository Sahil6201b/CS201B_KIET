struct node {
	int data;
	struct node *next;
};
typedef struct node *NODE;

int isPresent(NODE first, int x) {
	while (first != NULL) {
		if (first->data == x)
			return 1;
		first = first->next;
	}
	return 0;
}

NODE createAndAddNodes(NODE first) {
	NODE temp, q;
	int x;
	printf("Enter element : ");
	scanf("%d", &x);
	while(x != -1) {
		temp = (NODE)malloc(sizeof(struct node));
		temp->data = x;
		temp->next = NULL;
		if(first == NULL) {
			first = temp;
		} else {
			q->next = temp;
		}
		q = temp;
		printf("Enter element : ");
		scanf("%d", &x);
	}
	return first;  
}

void print(NODE first) {
	NODE q = first;
	if (first == NULL) {
		printf("Single Linked List is empty\n");
	} else {
		printf("Elements in the list are : ");
		while (q != NULL) {
			printf("%d---> ", q->data);
			q = q->next;
		}
		printf("NULL\n");
	}
}

NODE concatenate(NODE t1, NODE t2) {
	// Write the code
	NODE temp;
	
	if (t1 == NULL)
		return t2;
	
	temp = t1;
	while (temp->next != NULL)
		temp = temp->next;
	
	temp->next = t2;
	return t1;
}

NODE unionSLL(NODE l1, NODE l2) {
	// Write the code
	
	NODE result = NULL, temp, newNode, last;
	
	temp = concatenate(l1,l2);

	while (temp != NULL) {
		if (!isPresent(result, temp->data)) {
			newNode = (NODE)malloc(sizeof(struct node));
			newNode->data = temp->data;
			newNode->next = NULL;
			
			if (result == NULL)
				result = newNode;
			else
				last->next = newNode;
			
			last = newNode;
		}
		temp = temp->next;
	}
	
	return result;
}
