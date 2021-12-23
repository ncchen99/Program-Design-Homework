#include <stdio.h>

int main() {
    unsigned char ch[10000] = {};
    ch[0] = 122 + 20;
    printf("%c", ch[0]);
    return 0;
}