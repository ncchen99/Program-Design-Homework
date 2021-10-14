#include <stdio.h>
int main() {
  int n;
  while (1) {
    scanf("%d", &n);
    // 如果 n 不是 0
    if (n) {
      int isFirstFactor = 1;
      printf("%d = ", n);
      int factor = 2;
      while (n != 1) {
        // 如果 factor 是 n 的因數
        if (n % factor == 0) {
          // 是第一個印出來的因數
          if (isFirstFactor) {
            printf("%d", factor);
            isFirstFactor = 0;
          } else {
            printf(" * %d", factor);
          }
          n = n / factor;
        } else {
          factor++;
        }
      }
      printf("\n");
    } else {
      break;
    }
  }
}
