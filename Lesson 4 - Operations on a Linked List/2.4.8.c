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
	poly temp = head;
	while(temp != NULL) {
		printf("%d X^ %d ---> ", temp -> coeff, temp -> exp);
		temp = temp -> next;
	}
	printf("NULL\n");
}

poly mul(poly head1, poly head2) {
	poly result = NULL;

    if (head1 == NULL || head2 == NULL)
        return NULL;

    poly ptr1 = head1;

    while (ptr1 != NULL) {

        poly ptr2 = head2;

        while (ptr2 != NULL) {

            poly temp = (poly)malloc(sizeof(struct polynomial));
            temp->coeff = ptr1->coeff * ptr2->coeff;
            temp->exp = ptr1->exp + ptr2->exp;
            temp->next = NULL;

            result = addTerm(result, temp);

            ptr2 = ptr2->next;
        }

        ptr1 = ptr1->next;
    }

    return result;
}
