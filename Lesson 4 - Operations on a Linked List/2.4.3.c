#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *next;
};
typedef struct node *NODE;

NODE createNodeInCLL() {
	NODE temp = (NODE)malloc(sizeof(struct node));
	temp->next = NULL;
	return temp;
}

int countNodes(NODE first) {
	if(first == NULL) return 0;

	int count = 0;
	NODE temp = first;

	do {
		count++;
		temp = temp->next;
	} while(temp != first);

	return count;
}

NODE insertAtPositionInCLL( NODE first, int pos, int x  ) {
	int count = countNodes(first);

	if(pos > count + 1) {
		printf("Position not found\n");
		return first;
	}

	NODE newNode = createNodeInCLL();
	newNode->data = x;

	if(first == NULL) {
		newNode->next = newNode;
		return newNode;
	}

	if(pos == 1) {
		NODE last = first;
		while(last->next != first)
			last = last->next;

		newNode->next = first;
		last->next = newNode;
		first = newNode;
		return first;
	}

	NODE temp = first;
	for(int i=1;i<pos-1;i++)
		temp = temp->next;

	newNode->next = temp->next;
	temp->next = newNode;

	return first;
}

NODE deleteAtPositionInCLL(  NODE first, int pos ) {
	int count = countNodes(first);

	if(pos <= 0 || pos > count) {
		printf("Position not found\n");
		return first;
	}

	NODE temp = first;

	if(pos == 1) {

		int val = first->data;

		if(first->next == first) {
			free(first);
			printf("Deleted element: %d\n", val);
			return NULL;
		}

		NODE last = first;
		while(last->next != first)
			last = last->next;

		first = first->next;
		last->next = first;

		free(temp);

		printf("Deleted element: %d\n", val);
		return first;
	}

	NODE prev = NULL;

	for(int i=1;i<pos;i++) {
		prev = temp;
		temp = temp->next;
	}

	prev->next = temp->next;

	printf("Deleted element: %d\n", temp->data);

	free(temp);

	return first;

}

void traverseListInCLL( NODE first  ) {
	NODE temp = first;
	do {
		printf("%d --> ", temp->data);
		temp = temp->next;
	} while(temp != first);
	printf("\n");
}

void main() {
	NODE first = NULL;
	int x, pos, op;
	while(1) {
		printf("1.Insert 2.Delete 3.Display 4.Exit\n");
		printf("choice: ");
		scanf("%d", &op);
		switch(op) {
			case 1:	printf("Position: ");
					scanf("%d", &pos);
					if (pos <= 0) {
						printf("Position not found\n");
					} else {
						printf("Element: ");
						scanf("%d", &x);
						first = insertAtPositionInCLL(first, pos, x);
					}
					break;
	        case 2:	if (first == NULL) {
						printf("CLL is empty\n");
					} else {
						printf("Position: ");
						scanf("%d", &pos);
						first = deleteAtPositionInCLL(first, pos);
					}
					break;
			case 3:	if (first == NULL) {
						printf("CLL is empty\n");
					} else {
						printf("Elements in CLL are: ");
						traverseListInCLL(first);
					}
					break;
			case 4:	exit(0);
		}
	}
}
