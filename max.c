#include "max.h"
#include <assert.h>
#include <stdio.h>

int max(int *numbers, int size) {
  assert(size > 0); // assert the assumption from the exercise description
  int max_value = 0;

  // this goes through and compares all values of the array
  for (int i = 0; i < size; i++) {
    if (numbers[i] > max_value)
      max_value = numbers[i];
  }
  return max_value;
}

#ifndef TEST

int main() {
  int liste[6] = {1,6,3,4,5,2};
  
  // since liste is an array, which is a type of pointer, you don't need to write &liste
  int max_value = max(liste, 6);
  printf("Max: %d\n", max_value);
	return 0;
}

#endif
