#include <stdlib.h>
#include <stdio.h>

int main (void) {
    int num1;
    scanf("%d", &num1);
    char str2[num1][52];
    for(int i = 0; i < num1; i++) {
        scanf("%s", str2[i]);
    }
    if(num1 == 1) {
      printf("%s", str2[0]);
      exit(0);
    }
    for(int i = 1; i < num1; i++) {
        for(int j = 0; j < sizeof(str2[i]); j++) {
            {
                if(str2[0][j] != str2[i][j]){
                    str2[0][j] = '?';
                }
            }
        }
    }
    printf("%s", str2[0]);
    return 0;
}