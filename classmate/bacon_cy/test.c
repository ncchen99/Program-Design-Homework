#include <stdio.h>
union my_union {
  int i;
  double d;
} u1;
int main() {
  union my_union u2 = {0};
  u1.d = (double)u2.i;
  printf("%f\n", u1.d);
  return 0;
}