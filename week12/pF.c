#include <stdio.h>

void addition();

void print_binary(void* n) {
    for (int i = 31; i >= 0; --i) {
        printf("%d", (*(int*)n >> i) & 1);
        if (i && !(i % 8)) printf(" ");
    }
}

int main() {
    addition();
    return 0;
}

void addition() {
    float a, b;
    int* d = &a;
    int* e = &b;
    scanf("%f%f", &a, &b);
    printf("   ");
    print_binary(&a);
    printf("\n+) ");
    print_binary(&b);
    printf("\n---------------------------------------\n   ");
    int c = *d + *e;
    print_binary(&c);
    printf("\n%d + %d = %d", (int)a, (int)b, c);
}