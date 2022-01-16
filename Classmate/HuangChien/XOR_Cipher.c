#include <stdio.h>

int main() {
    char key[1002], data[10002];
    fgets(key, 1002, stdin);
    fgets(data, 10002, stdin);
    for (int i = 0, j = 0;; i++, j++) {
        if (key[i] == '\n') i = 0;
        if (data[j] == '\n')
            break;
        printf("%c", key[i] ^ data[j]);
    }
    return 0;
}