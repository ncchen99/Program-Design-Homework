#include <stdio.h>
#include <string.h>

int main() {
    char K[10000] = {0}, data[100000] = {0};
    gets(K);
    gets(data);
    int len = strlen(data);
    for (int i = 0; i < len;) {
        for (int k = 0; k < strlen(K) && i < len; k++, i++) {
            data[i] = data[i] ^ K[k];
            printf("%c", data[i]);
        }
    }
    return 0;
}