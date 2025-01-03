#include "main.h"

int sub(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2,
        Dlist **head3, Dlist **tail3, char **argv) {
  int sign = 0;
  int length1 = strlen(argv[1]);
  int length2 = strlen(argv[3]);
  printf("%d\n%d\n", length1, length2);
  if (length1 > length2) {
    create_list(head1, tail1, argv[1], length1);
    create_list(head2, tail2, argv[3], length2);

  } else if (length1 < length2) {
    create_list(head1, tail1, argv[3], length2);
    create_list(head2, tail2, argv[1], length1);
    sign = 1;
  } else {
    int res = strcmp(argv[1], argv[3]);
    if (res == 0) {
      printf("The result is 0\n");
      return SUCCESS;
    }
    if (res > 0) {
      create_list(head1, tail1, argv[1], length1);
      create_list(head2, tail2, argv[3], length2);
    } else {
      create_list(head1, tail1, argv[3], length2);
      create_list(head2, tail2, argv[1], length1);
      sign = 1;
    }
  }

  Dlist *temp1 = *head1;
  Dlist *temp2 = *head2;

  while (temp1 != NULL) {
    printf("%d -> ", temp1->data);
    temp1 = temp1->next;
  }
  printf("Null\n");

  while (temp2 != NULL) {
    printf("%d -> ", temp2->data);
    temp2 = temp2->next;
  }
  printf("Null\n");

  Dlist *t1 = *tail1;
  Dlist *t2 = *tail2;

  int diff = 0;
  int borrow = 0;

  while (t1 != NULL || t2 != NULL || borrow != 0) {
    int num1;
    int num2;
    if (t1 == NULL) {
      num1 = 0;
    } else {
      num1 = t1->data;
    }
    if (borrow == 1) {
      num1 = num1 - 1;
    }
    if (t2 == NULL) {
      num2 = 0;
    } else {
      num2 = t2->data;
    }
    if (num1 < num2) {
      borrow = 1;
      num1 = num1 + 10;
    } else {
      borrow = 0;
    }

    diff = num1 - num2;

    Dlist *result = malloc(sizeof(Dlist));
    if (result == NULL) {
      return FAILURE;
    }

    result->data = diff;
    result->prev = NULL;
    result->next = *head3;
    if (*head3 != NULL) {
      (*head3)->prev = result;
    } else {
      *tail3 = result;
    }
    *head3 = result;

    if (t1 != NULL) {
      t1 = t1->prev;
    }
    if (t2 != NULL) {
      t2 = t2->prev;
    }
  }
  // Remove leading zeros from head3 if necessary
  Dlist *temp3 = *head3;
  while (temp3 != NULL && temp3->data == 0) {
    Dlist *toDelete = temp3;  // Node to delete
    temp3 = temp3->next;      // Move to next node
    free(toDelete);           // Free the leading zero
  }
  *head3 = temp3;  // Update head3 to new list without leading zeros

  printf("The Result is: ");
  if (sign == 1) {
    printf("-");
  }
  while (temp3 != NULL) {
    printf("%d", temp3->data);
    temp3 = temp3->next;
  }
  printf("\n");
  return SUCCESS;
}