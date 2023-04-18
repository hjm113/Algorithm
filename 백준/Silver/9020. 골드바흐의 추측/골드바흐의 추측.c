#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>

int ary[10010];

int main() {
  for(int i = 0; i < 5500; i++) {
    ary[i] = i + 2;
  }
  for(int i = 2; i < 5500; i++) {
    if(ary[i-2] == 1) {
      continue;
    }
    for(int j = i * i; j < 5500; j=j+i) {
      if(j % i == 0) {
        ary[j-2] = 1;
      }
    }
  }
  int count;
  
  scanf("%d", &count);
  for(int i = 0; i < count; i++) {
    int num;
    int fst;
    int snd;
    int cnt = 0;
    scanf("%d", &num);
    int half = num / 2;
    for(int q = half - 2; q >= 0; q--) {
      if(ary[q] == 1) {
        continue;
      }
      for(int p = half - 2; p <= num; p++) {
        if(ary[p] == 1) {
          continue;
        }
        if(ary[q] + ary[p] == num) {
          fst = q;
          snd = p;
          printf("%d %d\n", ary[q], ary[p]);
          cnt = 1;
        }
      }
      if(cnt == 1) {
        break;
      }
    }
  }
}
  
  