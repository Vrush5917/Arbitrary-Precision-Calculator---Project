#include "main.h"

int add(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2,
        Dlist **head3, Dlist **tail3, char **argv) {
  int length1 = strlen(argv[1]);
  int length2 = strlen(argv[3]);

  create_list(head1, tail1, argv[1], length1);
  create_list(head2, tail2, argv[3], length2);

  Dlist *t1 = *tail1;
  Dlist *t2 = *tail2;

  int sum = 0;
  int carry = 0;

  while (t1 != NULL || t2 != NULL || carry != 0) {
    int num1;
    int num2;

    if (t1 == NULL) {
      num1 = 0;
    } else {
      num1 = t1->data;
    }
    if (t2 == NULL) {
      num2 = 0;
    } else {
      num2 = t2->data;
    }

    // Calculate sum and carry
    sum = num1 + num2 + carry;
    carry = sum / 10;  // Carry for the next iteration
    sum = sum % 10;    // Digit to store in the current node

    Dlist *result = malloc(sizeof(Dlist));
    if (result == NULL) {
      return FAILURE;
    }
    result->data = sum;
    result->prev = NULL;
    result->next = *head3;
    if (*head3 != NULL) {
      (*head3)->prev = result;

    } else {
      (*tail3) = result;
    }
    *head3 = result;

    if (t1 != NULL) {
      t1 = t1->prev;
    }
    if (t2 != NULL) {
      t2 = t2->prev;
    }
  }

  Dlist *temp3 = *head3;
  printf("The Result is: ");
  while (temp3 != NULL) {
    printf("%d", temp3->data);
    temp3 = temp3->next;
  }
  printf("\n");
  return SUCCESS;
}