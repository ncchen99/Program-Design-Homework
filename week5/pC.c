#include <stdio.h>
#include <string.h>
int main() {
    int n, cp, hp, s, nb;
    scanf("%d%d%d%d", &n, &cp, &hp, &s);
    nb = n;  // 😎🚀🚀
    if (cp < 100)
        n -= 1;
    else if (cp >= 100 && cp <= 600)
        if (hp > 100)
            n -= 8;
        else
            n -= 5;
    else if (hp > 100)
        n -= 25;
    else
        n -= 15;
    if (n >= 0 && !(s > 4 && nb - n > 6))
        printf("YES\n%d", n);
    else
        printf("NO");
}