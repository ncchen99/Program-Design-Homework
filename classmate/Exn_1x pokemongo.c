#include <stdio.h>

int main() {
    int n = 0, cp = 0, hp = 0, s = 0;
    scanf("%d%d%d%d", &n, &cp, &hp, &s);

    if (s > 4 && cp >= 100)  //  一定抓不到
        n = -1;
    else {
        if (cp < 100) {
            n--;
        } else if (cp >= 100 && cp <= 600) {
            n -= 5;
            if (hp > 100)
                n -= 3;
        } else if (cp > 600) {
            n -= 15;
            if (hp > 200)
                n -= 10;
        }
    }
    if (n >= 0)
        printf("YES\n%d", n);
    else
        printf("NO\n");
    return 0;
}