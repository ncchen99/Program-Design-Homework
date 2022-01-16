#include <stdio.h>
#include <string.h>
int main() {
    char sentence[50000] = {};
    int n = 0, i = 0;
    scanf("%d", &n);
    char move_charactor[5000] = {};
    scanf("%s\n", move_charactor);
    fgets(sentence, 50000, stdin);
    int m = strlen(sentence), k = 0;

    for (i = 0; i < m; i++) {
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
    for (int i = 0; i < m; ++i) {
        printf("%c", sentence[i]);
    }

    return 0;
}
