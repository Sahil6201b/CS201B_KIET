struct node {
	int data;
	struct node *next;
};
typedef struct node *NODE;

NODE createAndAddNodes(NODE first) {
	int x;
    NODE temp, newNode;
    
    while (1) {
        printf("Enter element : ");
        scanf("%d", &x);
        
        if (x == -1)
            break;
        
        newNode = (NODE)malloc(sizeof(struct node));
        newNode->data = x;
        newNode->next = NULL;
        
        if (first == NULL) {
            first = newNode;
        } else {
            temp = first;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    return first;
}

NODE concatenate(NODE t1, NODE t2) {
	NODE temp;
    
    if (t1 == NULL)
        return t2;
    
    temp = t1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    temp->next = t2;
    
    return t1;
}

void print(NODE first) {
	NODE q = first;
	if (first == NULL) {
		printf("Single Linked List is empty\n");
	} else {
		while (q != NULL) {
			printf("%d---> ", q->data);
			q = q->next;
		}
		printf("NULL\n");
	}
}
