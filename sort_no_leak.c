/*
 Create an src/sort_no_leak.c program to fix the memory leak in the src/sort.c program. If there was no leak in the first place, then shrug the shoulders and copy src/sort.c to src/sort_no_leak.c.
 **/

#include <stdio.h>
#include <stdlib.h>
#define NUM_AR 10
int input(int *array);
void sort(int *array);
void output(int *array);

int main() {
  int n;
  if (scanf("%d", &n) != 1 || n <= 0 || n > 10) {
    printf("n/a");
    return 1;
  }
  int *data = malloc(n * sizeof(int));
  if (input(data)) {
    printf("n/a\n");
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
