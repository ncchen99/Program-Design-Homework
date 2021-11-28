#include <stdio.h>
#include <string.h>
int main() {
  // 使用字串
  char s[101];
  scanf("%s", s);
  // strlen() 可以取得字串長度
  for (int i = 0; i < strlen(s); i++) {
    if (s[i] == '0')
      printf("----- ");
    else if (s[i] == '1')
      printf(".---- ");
    else if (s[i] == '2')
      printf("..--- ");
    else if (s[i] == '3')
      printf("...-- ");
    else if (s[i] == '4')
      printf("....- ");
    else if (s[i] == '5')
      printf("..... ");
    else if (s[i] == '6')
      printf("-.... ");
    else if (s[i] == '7')
      printf("--... ");
    else if (s[i] == '8')
      printf("---.. ");
    else if (s[i] == '9')
      printf("----. ");
  }
}
