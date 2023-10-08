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
  assert(l != NULL); // same precondition as add
  int counter = 0;
  node *p = l->next; // declare a pointer p of type node
  while (p != NULL) { // this is true while the pointer has not reached the end of the list yet
    p = p->next; // move to the next element
    counter++;
  }
	return counter;
}

// exersice 3.c and 3.d
void printout(node *l) {
  // pre:  head points to the first, empty element.
  //       The last element's next is NULL
  // post: The values of the list are printed out
  assert(l != NULL); // same precondition as add
  node *p = l->next; // declare a pointer p of type node
  while (p != NULL) { // this is true while the pointer has not reached the end of the list yet
    printf("%d, ", p->data);
    p = p->next; // move to the next element
  }
  printf("\n");
}

// exersice 3.e
int largest(node *l) {
  // pre:  head poinst to the first, empty element.
  // 	     The last element's next is NULL.
  // post: Returns the largest value of the list
  assert(l != NULL); // same precondition as add
  node *p = l->next; // declare a pointer p of type node
  int max = p->data;
  while (p != NULL) { // this is true while the pointer has not reached the end of the list ye
    if (p->data > max) 
      max = p->data; // if the new element is larger than the current largest, replace it
    p = p->next; // move to the next element
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
