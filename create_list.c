#include "main.h"

int create_list(Dlist **head, Dlist **tail, char *str, int length) {
  for (int i = 0; i < length; i++) {
    Dlist *list = malloc(sizeof(Dlist));
    if (list == NULL) {
      return FAILURE;
    }
    list->data = str[i] - '0';
    list->next = NULL;
    list->prev = NULL;
    if (*head == NULL) {
      list->prev = NULL;
      *head = list;
      *tail = list;
    } else {
      list->prev = *tail;
      (*tail)->next = list;
      *tail = list;
    }
  }
}