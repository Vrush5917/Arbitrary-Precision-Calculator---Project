#include "main.h"

int sub_list(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2,
             Dlist **head3, Dlist **tail3, char **argv) {
  Dlist *t1 = *tail1;
  Dlist *t2 = *tail2;

  int diff = 0;
  int borrow = 0;

  while (t1 != NULL || t2 != NULL || borrow != 0) {
    int num1 = (t1 != NULL) ? t1->data : 0;
    int num2 = (t2 != NULL) ? t2->data : 0;

    if (borrow == 1) {
      num1 -= 1;
      borrow = 0;
    }

    if (num1 < num2) {
      borrow = 1;
      num1 += 10;
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

    // Move to the previous nodes
    if (t1 != NULL) t1 = t1->prev;
    if (t2 != NULL) t2 = t2->prev;
  }

  // Remove leading zeros from head3 if necessary
  while (*head3 != NULL && (*head3)->data == 0) {
    Dlist *toDelete = *head3;
    *head3 = (*head3)->next;
    free(toDelete);
  }

  if (*head3 != NULL) {
    (*head3)->prev = NULL;
  } else {
    *tail3 = NULL;  // If all nodes were zero, reset tail as well
  }

  return SUCCESS;
}

void copy_list(Dlist **head1, Dlist **tail1, Dlist **head3, Dlist **tail3) {
  // Free the current head1 list
  clear_list(head1, tail1);

  Dlist *temp3 = *head3;
  while (temp3 != NULL) {
    Dlist *newNode = malloc(sizeof(Dlist));
    newNode->data = temp3->data;
    newNode->next = NULL;
    newNode->prev = *tail1;

    if (*tail1 != NULL) {
      (*tail1)->next = newNode;
    } else {
      *head1 = newNode;
    }

    *tail1 = newNode;
    temp3 = temp3->next;
  }
}

void clear_list(Dlist **head, Dlist **tail) {
  Dlist *temp;
  while (*head != NULL) {
    temp = *head;
    *head = (*head)->next;
    free(temp);
  }
  *tail = NULL;
}
