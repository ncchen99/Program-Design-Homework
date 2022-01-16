#include <stdio.h>

int main() {
    int sentence[65];
    sentence[64] = '\0';
    for (int i = 0; i < 64; i++) {
        scanf("%lc", &sentence[i]);
    }
    char move_charactor[5] = "meow";
    int n = 4;  // meow 的長度
    for (int i = 0, k = 0; i < 64; i++) {
        if (sentence[i] >= 'a' && sentence[i] <= 'z') {
            if (sentence[i] + (move_charactor[k % n] - 'a') <= 'z')
                sentence[i] += move_charactor[k % n] - 'a';
            else
                sentence[i] = sentence[i] + move_charactor[k % n] - 'a' - 26;
            k++;
        }
        if (sentence[i] >= 'A' && sentence[i] <= 'Z') {
            if (sentence[i] + (move_charactor[k % n] - 'a') <= 'Z')
                sentence[i] += move_charactor[k % n] - 'a';
            else
                sentence[i] = sentence[i] + move_charactor[k % n] - 'a' - 26;
            k++;
        }
    }

    for (int i = 0; i < 64; ++i) {
        printf("%c", sentence[i]);
    }

    return 0;
}
