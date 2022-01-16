#include <stdio.h>

void addition();

void print_binary(void *n) {
    for (int i = 31; i >= 0; --i) {
        printf("%d", (*(int *)n >> i) & 1);
        if (i && !(i % 8)) printf(" ");
    }
}

int main() {
    addition();
    return 0;
}

#include <stdlib.h>

char *byte2string(void *n) {
    char *s = malloc(sizeof(char) * 100);
    int j = 0;
    for (int i = 31; i >= 0; --i) {
        s[j++] = '0' + ((*(int *)n >> i) & 1);
        if (i && !(i % 8)) s[j++] = ' ';
    }
    s[j] = '\0';
    return s;
}
void addition() {
    float a, b, *d = &a, *e = &b;
    scanf("%f%f", &a, &b);
    int c = (*(int *)d + *(int *)e);
    printf("   %s\n+) %s\n---------------------------------------\n   %s\n%d + %d = %d", byte2string(&a), byte2string(&b), byte2string(&c), (int)a, (int)b, c);
}