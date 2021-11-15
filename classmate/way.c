#include <stdio.h>
int main() {
    __uint128_t a = 1.88e25;
    __uint128_t b = 9.4e24;
    printf("%lld", (long long)(a / b));
}