#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main (void) {
  int num;
  scanf("%d", &num);
  for(int i = num - 1; i >= 0; i--) {
    for(int j = 0; j < i; j++) {
      printf(" ");
    }
    for(int j = 0; j < num - i; j++) {
      printf("*");
    }
    printf("\n");
  }
}