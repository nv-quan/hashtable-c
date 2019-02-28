#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int a = 10;
  int *p = (int*) malloc(sizeof(int));
  *p = 2;
  printf("*p = %d\n", *p);
  printf("p = %d\n", p);
  free(p);
  printf("p = %d\n", p);
  printf("*p = %d\n", *p);
}
