struct node {
	int data;
	struct node *next;
};
typedef struct node * NODE;

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

NODE sort(NODE first) {
	// Write the code
	NODE i, j;
    int temp;
    
    for (i = first; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    return first;
}

NODE add(NODE l3,int x) {
	// Write the code
	NODE temp, q;
    
    temp = (NODE)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = NULL;
    
    if (l3 == NULL)
        return temp;
    
    q = l3;
    while (q->next != NULL)
        q = q->next;
    
    q->next = temp;
    return l3;
}

NODE intersectionSLL(NODE l1,NODE l2) {
	// Write the code
	NODE l3 = NULL;
    
    while (l1 != NULL && l2 != NULL) {
        
        if (l1->data == l2->data) {
            l3 = add(l3, l1->data);
            l1 = l1->next;
            l2 = l2->next;
        }
        else if (l1->data < l2->data) {
            l1 = l1->next;
        }
        else {
            l2 = l2->next;
        }
    }
    
    return l3;
}

void print(NODE first) {
	NODE q = first;
	if (first == NULL) {
		printf("Single Linked List is empty\n");
	} else {
		printf("Elements in the list are : ");
		while (q != NULL) {
			printf("%d---> ", q -> data);
			q = q -> next;
		}
		printf("NULL\n");
	}
}
