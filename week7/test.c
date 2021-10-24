#include <stdio.h>

int aaa(int f) {
    int t = 0;
    for (int r = 1; f > 0; r *= 6, f /= 10)
        t += (f % 10) * r;
    f = t;
}

int main() {
    printf("%d\n", aaa(20));
}