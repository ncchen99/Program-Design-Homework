#include <stdio.h>
#include <string.h>

int main() {
    int B, W, T, G, M, S, I, earn = 0;
    scanf("%d %d %d %d %d %d %d ", &B, &W, &T, &G, &M, &S, &I);
    B *= 1000;
    W *= 1000;
    T *= 1000;
    G *= 1000;
    M *= 1000;
    S *= 1000;
    I *= 1000;
    int x;
    scanf("%d ", &x);
    int s, i;
    for (int k = 0; k < x; k++) {
        char str[5];
        scanf("%s %d/%d", str, &s, &i);
        printf("%s ", str);
        if (s == 2)
            S -= 3;
        else if (s == 3)
            S -= 5;
        else if (s == 4)
            S -= 7;
        else if (s == 5)
            S -= 10;
        if (i == 2)
            I -= 30;
        else if (i == 3)
            I -= 50;
        else if (i == 4)
            I -= 70;
        else if (i == 5)
            I -= 100;
        if (strcmp(str, "G") == 0) {
            G -= 500;
            earn += 20;
        } else if (strcmp(str, "B") == 0) {
            B -= 500;
            earn += 20;
        } else if (strcmp(str, "T") == 0) {
            T -= 500;
            earn += 30;
        } else if (strcmp(str, "W") == 0) {
            W -= 500;
            earn += 15;
        } else if (strcmp(str, "GT") == 0) {
            G -= 250;
            T -= 250;
            earn += 45;
        } else if (strcmp(str, "WT") == 0) {
            W -= 150;
            T -= 350;
            earn += 40;
        } else if (strcmp(str, "BM") == 0) {
            B -= 200;
            M -= 300;
            earn += 35;
        } else if (strcmp(str, "TM") == 0) {
            T -= 200;
            M -= 300;
            earn += 45;
        } else if (strcmp(str, "WM") == 0) {
            W -= 200;
            M -= 300;
            earn += 30;
        }
        printf("%d %d %d %d %d %d %d \n%d \n", B, W, T, G, M, S, I, earn);
    }
    printf("%d %d %d %d %d %d %d \n%d \n", B, W, T, G, M, S, I, earn);
    return 0;
}