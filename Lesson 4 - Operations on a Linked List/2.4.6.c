struct polynomial {
	int coeff;
	int exp;
	struct polynomial *next;
};
typedef struct polynomial *poly;

poly addTerm(poly head, poly temp) {
	//write code here
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

poly add(poly head1, poly head2) {
	//write code here
	poly result = NULL;

    while (head1 != NULL && head2 != NULL) {

        poly temp = (poly)malloc(sizeof(struct polynomial));
        temp->next = NULL;

        if (head1->exp > head2->exp) {
            temp->coeff = head1->coeff;
            temp->exp = head1->exp;
            head1 = head1->next;
        }
        else if (head1->exp < head2->exp) {
            temp->coeff = head2->coeff;
            temp->exp = head2->exp;
            head2 = head2->next;
        }
        else {  // same exponent
            temp->coeff = head1->coeff + head2->coeff;
            temp->exp = head1->exp;
            head1 = head1->next;
            head2 = head2->next;
        }

        result = addTerm(result, temp);
    }

    // If first polynomial has remaining terms
    while (head1 != NULL) {
        poly temp = (poly)malloc(sizeof(struct polynomial));
        temp->coeff = head1->coeff;
        temp->exp = head1->exp;
        temp->next = NULL;
        result = addTerm(result, temp);
        head1 = head1->next;
    }

    // If second polynomial has remaining terms
    while (head2 != NULL) {
        poly temp = (poly)malloc(sizeof(struct polynomial));
        temp->coeff = head2->coeff;
        temp->exp = head2->exp;
        temp->next = NULL;
        result = addTerm(result, temp);
        head2 = head2->next;
    }

    return result;
}
