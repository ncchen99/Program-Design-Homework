#include <stdio.h>
int main() {
  union {
    float a;
    unsigned char later[4];
  } test;
  scanf("%f", &test.a);
  unsigned sum = test.later[0] + test.later[1] + test.later[2] + test.later[3];
  printf("%d", sum);
}