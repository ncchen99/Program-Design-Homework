#include <stdio.h>
#include <stdlib.h>
int* poly(int*, int*, int*);
int t;
int main() {
    int a, b, c;
    int *A, *B, *C;
    scanf("%d %d %d", &a, &b, &c);
    A = &a;
    B = &b;
    C = &c;
    if (a < 0) A = NULL;
    if (b < 0) B = NULL;
    if (c < 0) C = NULL;

    int* result = poly(A, B, C);
    printf("%d", *result);
    return 0;
}
#include <stdlib.h>
int* poly(int* A, int* B, int* C) {
    int z = 0;
    A = (A ? A : &z);
    B = (B ? B : &z);
    C = (C ? C : &z);
    t = ((*A) * (*A) * (*A) + (*B) * (*B) + (*C));
    return &t;
}