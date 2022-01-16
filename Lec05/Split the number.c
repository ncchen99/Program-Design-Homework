#include <stdio.h>
#include <string.h>
int main() {
    char s[101] = {0};
    scanf("%s", s);
    for (int i = 0; i < 3 - strlen(s); i++) printf("0 ");
    for (int i = 0; i < strlen(s); i++) printf("%c ", s[i]);
}