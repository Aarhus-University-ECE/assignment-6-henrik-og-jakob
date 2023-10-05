#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

void add(node *head, int x) {
  // pre:  head points to the first, empty element.
  //       The last element's next is NULL
  // post: A new node containing x is added to the end of the list
  assert(head != NULL);
  node *p = head;
  while (p->next != NULL) {
    p = p->next;
  } // p points to the last element
  node *element = malloc(sizeof(node));
  element->next = NULL;
  element->data = x;
  p->next = element;
}

// exersice 3.b
int size(node *l) {
  assert(l != NULL);
  int counter = 0;
  node *p = l->next;
  while (p != NULL) {
    p = p->next;
    counter++;
  }
	return counter;
}

// exersice 3.c and 3.d
void printout(node *l) {
  // pre:  head points to the first, empty element.
  //       The last element's next is NULL
  // post: The values of the list are printed out
  assert(l != NULL);
  node *p = l->next;
  while (p != NULL) {
    printf("%d, ", p->data);
    p = p->next;
  }
  printf("\n");
}

// exersice 3.e
int largest(node *l) {
  // pre:  head poinst to the first, empty element.
  // 	     The last element's next is NULL.
  // post: Returns the largest value of the list
  assert(l != NULL);
  node *p = l->next;
  int max = p->data;
  while (p != NULL) {
    if (p->data > max)
      max = p->data;
    p = p->next;
  }
  return max;
}

#ifndef TEST
int main() {
  node *list = malloc(sizeof(node));
  list->next = NULL; // create first empty element

  add(list, 1);
  add(list, 3);
  add(list, 2);
  // Show list here
  printf("%d\n", size(list));
  printout(list);
  printf("%d\n", largest(list));
  add(list, 2);
  // Show list here

  return 0;
}

#endif
