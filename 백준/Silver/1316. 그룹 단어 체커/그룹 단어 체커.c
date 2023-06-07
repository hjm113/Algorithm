#include <stdio.h>
#include <string.h> 

int main() {
  int num;
  scanf("%d", &num);
  char str[num + 500][200];
  int check = 0;
  int count = 0;
  for(int i = 0; i < num; i++) {
    scanf("%s", str[i]);
  }
  for(int i = 0; i < num; i++) {
    int len = strlen(str[i]);
    for(int j = 0; j < len; j++) {
      for(int k = 2; k < len; k++) {
        if(str[i][j] != str[i][j+1] && str[i][j] == str[i][j+k]) {
          check = 1;
        }
      }
    }
    if(check == 0) {
      count++;
    }
    check = 0;
  }
  printf("%d", count);
}