#include "main.h"

int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2,
             Dlist **head3, Dlist **tail3, char **argv) {
  int length1 = strlen(argv[1]);
  int length2 = strlen(argv[3]);

  create_list(head1, tail1, argv[1], length1);
  create_list(head2, tail2, argv[3], length2);

  printf("Operand1 is %s\n", argv[1]);
  printf("Operand2 is %s\n", argv[3]);

  printf("The length is %d\n", length1);
  printf("The length is %d\n", length2);

  int count = 1;

  // Continue until head1 becomes less than head2
  while (listzero(head1, tail1, head2, tail2) != SUCCESS) {
    // Perform subtraction
    if (sub_list(head1, tail1, head2, tail2, head3, tail3, argv) != SUCCESS) {
      return FAILURE;
    }

    // Update head1 with the result in head3
    copy_list(head1, tail1, head3, tail3);

    // Clear head3 for the next subtraction
    clear_list(head3, tail3);

    count++;
  }

  printf("The result is %d\n", count);  // This is the quotient
  return SUCCESS;
}

int listzero(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2) {
  Dlist *temp1 = *head1;
  Dlist *temp2 = *head2;

  // First, compare the lengths of the two lists (numbers)
  int len1 = 0, len2 = 0;

  // Calculate length of the first list (head1)
  while (temp1 != NULL) {
    len1++;
    temp1 = temp1->next;
  }

  // Calculate length of the second list (head2)
  while (temp2 != NULL) {
    len2++;
    temp2 = temp2->next;
  }

  // If the length of the first number is smaller, then head1 < head2
  if (len1 < len2) {
    return SUCCESS;  // head1 is smaller than head2, which means division should
                     // stop
  } else if (len1 > len2) {
    return FAILURE;  // head1 is larger, so continue dividing
  }

  // If the lengths are equal, compare digit by digit
  temp1 = *head1;
  temp2 = *head2;

  while (temp1 != NULL && temp2 != NULL) {
    if (temp1->data < temp2->data) {
      return SUCCESS;  // head1 is smaller
    } else if (temp1->data > temp2->data) {
      return FAILURE;  // head1 is larger, so continue dividing
    }

    temp1 = temp1->next;
    temp2 = temp2->next;
  }

  // If both numbers are the same
  return SUCCESS;  // head1 is equal to head2, continue the loop until result is
                   // zero
}
