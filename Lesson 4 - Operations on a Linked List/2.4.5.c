struct polynomial {
	int coeff;
	int exp;
	struct polynomial *next;
};
typedef struct polynomial *poly;

poly addTerm(poly head, poly temp) {
	if (head == NULL)
        return temp;

    poly curr = head;
    poly prev = NULL;

    while (curr != NULL && curr->exp > temp->exp) {
        prev = curr;
        curr = curr->next;
    }

    // Same exponent → add coefficients
    if (curr != NULL && curr->exp == temp->exp) {
        curr->coeff += temp->coeff;
        free(temp);
        return head;
    }

    // Insert at beginning
    if (prev == NULL) {
        temp->next = head;
        return temp;
    }

    // Insert in middle or end
    temp->next = curr;
    prev->next = temp;

    return head;
}

void print(poly head) {
	if (head == NULL) {
        printf("NULL\n");
        return;
    }

    poly temp = head;

    while (temp != NULL) {
        printf("%d X^ %d ---> ", temp->coeff, temp->exp);
        temp = temp->next;
    }

    printf("NULL\n");
}
