#include "main.h"

int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2,
                   Dlist **head3, Dlist **tail3, char **argv) {
  int length1 = strlen(argv[1]);
  int length2 = strlen(argv[3]);

  printf("%d\n%d\n", length1, length2);

  // Create the lists for the two numbers
  if (length1 > length2) {
    create_list(head1, tail1, argv[1], length1);
    create_list(head2, tail2, argv[3], length2);
  } else {
    create_list(head1, tail1, argv[3], length2);
    create_list(head2, tail2, argv[1], length1);
  }

  Dlist *t1 = *tail1;  // Pointer to the last node of the first number
  Dlist *t2 = *tail2;  // Pointer to the last node of the second number

  // Initialize head3 and tail3 to NULL
  *head3 = NULL;
  *tail3 = NULL;

  // Temporary storage for results
  int carry = 0;

  // Iterate through the second number (t2)
  for (int i = 0; i < length2; i++) {
    Dlist *currentResultHead = NULL;
    Dlist *currentResultTail = NULL;

    // Reset t1 to the tail of the first number for each digit in t2
    t1 = *tail1;

    // Create a counter for how many zeros to prepend based on the position in
    // t2
    for (int j = 0; j < i; j++) {
      Dlist *zeroNode = malloc(sizeof(Dlist));
      if (zeroNode == NULL) {
        return FAILURE;
      }
      zeroNode->data = 0;
      zeroNode->prev = currentResultTail;  // Link to the previous results
      zeroNode->next = NULL;

      if (currentResultTail) {
        currentResultTail->next = zeroNode;  // Link to the zero node
      } else {
        currentResultHead = zeroNode;  // First node
      }
      currentResultTail = zeroNode;  // Move to the last node
    }

    while (t1 != NULL) {
      int num1 = t1->data;
      int num2 = t2->data;

      // Calculate product and carry
      int prod = (num1 * num2) + carry;
      carry = prod / 10;
      prod = prod % 10;

      // Create a new node for the current digit result
      Dlist *resNode = malloc(sizeof(Dlist));
      if (resNode == NULL) {
        return FAILURE;
      }
      resNode->data = prod;
      resNode->prev = currentResultTail;  // Link to the previous results
      resNode->next = NULL;

      if (currentResultTail) {
        currentResultTail->next = resNode;  // Link to the new result node
      } else {
        currentResultHead = resNode;  // First node
      }
      currentResultTail = resNode;  // Move to the last node

      t1 = t1->prev;  // Move to the next digit of the first number
    }

    // If there's a remaining carry, create a node for it
    if (carry > 0) {
      Dlist *carryNode = malloc(sizeof(Dlist));
      if (carryNode == NULL) {
        return FAILURE;
      }
      carryNode->data = carry;
      carryNode->prev = currentResultTail;  // Link to the previous results
      carryNode->next = NULL;

      if (currentResultTail) {
        currentResultTail->next = carryNode;  // Link to the carry node
      } else {
        currentResultHead = carryNode;  // First node
      }
      currentResultTail = carryNode;  // Move to the last node
    }

    // Link currentResultHead to head3
    if (*head3 == NULL) {
      *head3 = currentResultHead;
      *tail3 = currentResultTail;
    } else {
      // Merge currentResultHead into head3
      Dlist *tempHead = *head3;
      while (currentResultHead != NULL) {
        Dlist *newNode = malloc(sizeof(Dlist));
        if (newNode == NULL) {
          return FAILURE;
        }
        newNode->data = currentResultHead->data;
        newNode->prev = tempHead;  // Link to the end of head3
        newNode->next = NULL;

        tempHead->next = newNode;  // Append to the result list
        tempHead = newNode;        // Update tempHead to the last node

        currentResultHead = currentResultHead->next;  // Move to the next digit
      }

      *tail3 = tempHead;  // Update tail3 to the last node of the result
    }

    t2 = t2->prev;  // Move to the next digit in the second number
    carry = 0;      // Reset carry for the next digit
  }

  // Reverse the list
  Dlist *cur = *head3;
  Dlist *next = NULL;
  Dlist *prev = NULL;
  while (cur != NULL) {
    next = cur->next;
    cur->next = prev;
    prev = cur;
    cur = next;
  }
  *head3 = prev;

  // Print the result
  Dlist *temp3 = *head3;
  printf("The Result is: ");
  while (temp3 != NULL) {
    printf("%d", temp3->data);
    temp3 = temp3->next;
  }
  printf("\n");

  return SUCCESS;
}
