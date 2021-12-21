#include <stdio.h>
#include <string.h>
int main() {
    char chch[1000], code[1000];
    int length = 0, start = 0, end = 0;
    scanf("%d", &length);
    scanf("%s\n%[^\n]", code, chch);
    length = strlen(chch);
    end = length;
    for (int i = start, k = 0; i < end; i++) {
        if (chch[i] >= 'A' && chch[i] <= 'Z') {
            chch[i] = (chch[i] - 65 + code[(k++ % strlen(code)) % length] - 97) % 26 + 65;
        } else if (chch[i] >= 'a' && chch[i] <= 'z') {
            chch[i] = (chch[i] - 97 + code[(k++ % 32) % strlen(code)] - 97) % 26 + 97;
        }
    }
    printf("%s\n", chch);
}