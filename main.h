#ifndef DLL_H
#define DLL_L

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCCESS 0
#define FAILURE -1

typedef struct node {
  int data;
  struct node *prev;
  struct node *next;
} Dlist;

int add(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2,
        Dlist **head3, Dlist **tail3, char **argv);

int sub(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2,
        Dlist **head3, Dlist **tail3, char **argv);

int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2,
             Dlist **head3, Dlist **tail3, char **argv);

int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2,
                   Dlist **head3, Dlist **tail3, char **argv);

int create_list(Dlist **head, Dlist **tail, char *str, int length);

int sub_list(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2,
             Dlist **head3, Dlist **tail3, char **argv);

int listzero(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2);

void copy_list(Dlist **head1, Dlist **tail1, Dlist **head3, Dlist **tail3);

void clear_list(Dlist **head, Dlist **tail);

#endif