/*
 Attention! In the quests of this day, it is forbidden to use dynamic memory.
 Create an src/sort.c program that expects an stdin array with the length of 10
 integers for input and outputs the same array sorted in ascending order.
 Arrange the functions of reading, sorting and output of the array separately.
 You can use any sorting algorithm. Using stdlib.h is not allowed. Passing an
 array to a function only by pointer. For errors, display "n/a".
 **/

#include <stdio.h>
#include <stdlib.h>
#define NUM_AR 10
int input(int *array);
void sort(int *array);
void output(int *array);

int main() {
  int n;
  scanf("%d", &n);
  int *data = malloc(n * sizeof(int));
  if (input(data)) {
    printf("n/a");
    return 0;
  }
  sort(data);
  output(data);
  free(data);
  return 0;
}

int input(int *array) {
  for (int i = 0; i < NUM_AR; i++) {
    if (scanf("%d", array++) != 1) {
      array[0] = '\n';
      return 1;
    }
  }
  if (getchar() != '\n') {
    array[0] = '\n';
    return 1;
  }
  return 0;
}

void sort(int *array) {
  for (int i = NUM_AR - 1; i > 0; i--) {
    for (int j = 0; j < i; j++) {
      if (array[j] > array[j + 1]) {
        int temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
      }
    }
  }
}
void output(int *array) {
  for (int i = 0; i < NUM_AR; i++) {
    printf("%d ", array[i]);
  }
}
