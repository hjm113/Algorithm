#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main (void) {
  int num1 = 28;
  int ary[num1];
  int max = 29;
  int ary1[30];
  for(int i = 1; i <= 30; i++) {
    ary1[i - 1] = i;
  }
  for(int i = 0; i < num1; i++) {
    scanf("%d", &ary[i]);
  }

  int check = 0; 
  int count = 0;
  int k = 0; 
  for(int i = 0; i < 30; i++) { 
    for(int j = 0; j < 28; j++) { 
      if(ary1[i] == ary[j]) {
      }
      else {
        check++;
      }
      if(check == 28) {
        printf("%d\n", ary1[i]);
      }
    }
    check = 0;
  }
}