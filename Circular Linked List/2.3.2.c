struct node {
	int data;
	struct node * next;
};
typedef struct node * NODE;

NODE createNodeInCLL() {
	NODE newNode = (NODE)malloc(sizeof(struct node));
	// if(newNode == NULL){
	// 	;
	// }
	newNode->next = NULL;
	return newNode;
}
