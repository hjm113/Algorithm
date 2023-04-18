#include <stdlib.h>
#include <stdio.h>

int main (void) {
    int num1;
    scanf("%d", &num1);
    int num2 = num1 + 1;
    int arr1[num2];
    int arr2[num2];
    int check = 0;
    
    for(int i = 0; i < num1; i++) {
        scanf("%d", &arr1[i]);
    }
    for(int q = 0; q < num1; q++) {
        check = 10000;
        int k = 0;
        for(int i = 0; i < num1; i++) {
            if(check > arr1[i]) {
                check = arr1[i];
                arr2[i] = q;
                k = i;
            }
        }
        arr1[k] = 10000;
    }
    for(int i = 0; i < num1; i++) {
        printf("%d ", arr2[i]);
    }
}