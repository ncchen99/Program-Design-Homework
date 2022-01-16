#include <stdio.h>
int main() {
  int n;
  scanf("%d", &n);
  // 要印 n 層星星
  for (int i = 0; i < n; i++) {
    // 先印空格
    for (int j = 0; j < n - i - 1; j++) printf(" ");
    // 再印星星 星星中間有一個空格
    for (int j = 0; j < i * 2 + 1; j++) {
      // 奇數位置印星星偶數位置印空格
      if (j % 2 == 0)
        printf("*");
      else
        printf(" ");
    }
    // 最後要換行
    printf("\n");
  }
}
