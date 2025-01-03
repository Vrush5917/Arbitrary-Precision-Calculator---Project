#include "main.h"

int main(int argc, char **argv) {
  Dlist *head1 = NULL;  // initialize the header to NULL
  Dlist *tail1 = NULL;  // initialize the tail to NULL

  Dlist *head2 = NULL;  // initialize the header to NULL
  Dlist *tail2 = NULL;  // initialize the tail to NULL

  Dlist *head3 = NULL;  // initialize the header to NULL
  Dlist *tail3 = NULL;  // initialize the tail to NULL

  if (argc != 4) {
    printf("Invalid Arguments\n");
    printf("Usage: ./a.out Operand1 Operator Operand2\n");
    return 1;  // return non-zero to indicate failure
  }

  switch (argv[2][0]) {
    case '+': {
      if (add(&head1, &tail1, &head2, &tail2, &head3, &tail3, argv) ==
          SUCCESS) {
        printf("Successfully performed the addition on two variables.\n");
      } else {
        printf("Failed to perform the addition on two variables.\n");
      }
    } break;

    case '-': {
      if (sub(&head1, &tail1, &head2, &tail2, &head3, &tail3, argv) ==
          SUCCESS) {
        printf("Successfully performed the substraction on two variables.\n");
      } else {
        printf("Failed to perform the substraction on two variables.\n");
      }
    } break;

    case '*': {
      /* Use \* as a operator for multiplication */
      if (multiplication(&head1, &tail1, &head2, &tail2, &head3, &tail3,
                         argv) == SUCCESS) {
        printf("Successfully performed the multiplication on two variables.\n");
      } else {
        printf("Failed to perform the multiplication on two variables.\n");
      }
    } break;

    case '/': {
      if (division(&head1, &tail1, &head2, &tail2, &head3, &tail3, argv) ==
          SUCCESS) {
        printf("Successfully performed the division on two variables.\n");
      } else {
        printf("Failed to perform the division on two variables.\n");
      }
    } break;

    default: {
      printf("Invalid Operator\n");
      break;
    }
  }
  return 0;
}