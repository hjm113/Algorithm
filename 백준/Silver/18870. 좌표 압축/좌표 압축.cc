#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>

typedef struct str12 {
  int val;
  int idx;
} coord;

int compare(const void* a, const void* b) {
  coord num1 = *(coord*)a;
  coord num2 = *(coord*)b;
  if(num1.val < num2.val) {
    return -1;
  }
  else if(num1.val > num2.val) {
    return 1;
  }
  return 0;
}

int main() {
  int num;
  scanf("%d", &num);
  coord arr[num];
  for(int i = 0; i < num; i++) {
    scanf("%d", &arr[i].val);
    arr[i].idx = i;
  }
  int ary[num];
  int min = -1000010000;
  int count = -1;
  qsort(arr, num, sizeof(coord), compare);
  for(int i = 0; i < num; i++) {
    if(arr[i].val > min) {
      min = arr[i].val;
      count++;
    }
    ary[arr[i].idx] = count;
  }
  for(int i = 0; i < num; i++) {
    printf("%d ", ary[i]);
  }
}
  
  