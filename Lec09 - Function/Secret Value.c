#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MODULUS 10007
int getSecret(int n);
int gcd(int a, int b);
int toInt(char* s, int b, int e);
int main() {
    int n;
    scanf("%d", &n);
    printf("%d", getSecret(n));
    // printf("GCD(%d, %d) = %d", n, m, gcd(n, m));
    return 0;
}
int toInt(char* s, int b, int e) {
    int tmp = 0;
    for (int i = e - 1, p = 1; i >= b; i--, p *= 10)
        tmp += (s[i] - '0') * p;
    return tmp;
}
int getSecret(int n) {
    char str[15];
    sprintf(str, "%d", n);
    if (strlen(str) == 1) {
        return atoi(str);
    }
    // printf("strlen: %ld\n", strlen(str));
    int f = toInt(str, 0, strlen(str) / 2), s = toInt(str, strlen(str) / 2, strlen(str));
    // printf("f:%d, s:%d\n", f, s);
    return (n % MODULUS + getSecret(gcd(f, s)) % MODULUS) % MODULUS;
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
