#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int rising_hope(char *R);

int main(int argc, char *argv[]) {
    char in[1005];

    scanf("%s", in);
    int hope = rising_hope(in);
    printf("%d\n", hope);

    return 0;
}

int rising_hope(char *R) {
    int h = 0;
    for (int i = 0; R[i] != '\0'; i++) {
        if (R[i] == 'P')
            h++;
        if (R[i] == 'N')
            h--;
    }
    return h;
}
