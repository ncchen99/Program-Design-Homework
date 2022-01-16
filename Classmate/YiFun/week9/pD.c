#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MODULUS 10007
int getSecret(int n);
int gcd(int a, int b);

int main() {
    int n;
    scanf("%d", &n);
    printf("%d", getSecret(n));
    return 0;
}

int getSecret(int n) {
    char str[15];
    sprintf(str, "%d", n);
    int a = n / pow(10, (strlen(str) - strlen(str) / 2)), b = n % (int)pow(10, strlen(str) - strlen(str) / 2);
    if (strlen(str) == 1) {
        return n;
    }
    // printf("a:%d, b:%d\n", a, b);
    return (n % MODULUS + getSecret(gcd(a, b)) % MODULUS) % MODULUS;
}

int gcd(int a, int b) {
    while (b != 0) {
        int tmp = a % b;
        // printf("%d%%%d = %d\n", a, b, a % b);
        a = b;
        b = tmp;
    }
    return a;
}