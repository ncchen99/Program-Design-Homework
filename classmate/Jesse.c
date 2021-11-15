#include <stdio.h>
#define MODULUS 10007
int getSecret(int n);
int gcd(int a, int b);

int main() {
    int n;
    scanf("%d", &n);
    printf("%d", getSecret(n));
    return 0;
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
int getSecret(int n) {
    int a = 0, b = 0, digits = 0, dec = 1, GCD = 0, num = 0;
    if (n / 10 == 0) {  //若為個位數，該數為密數
        return n;
    }
    num = n;
    while (num != 0) {  //計算位數
        num /= 10;
        digits++;
    }
    for (int i = 0; i < (digits + 1) / 2; i++)
        dec *= 10;
    a = n / dec;      //分離前半部
    b = n % dec;      //分離後半部
    GCD = gcd(a, b);  //找出最大公因數
    return (n % MODULUS + getSecret(GCD) % MODULUS);
}