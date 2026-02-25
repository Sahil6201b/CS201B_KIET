struct node {
	int data;
	struct node *next;
 };
typedef struct node *NODE;

NODE createNode() {
	NODE temp;
	temp = (NODE) malloc (sizeof(struct node));
	temp->next = NULL;
	return temp;
}
