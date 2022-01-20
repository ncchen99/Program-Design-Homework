#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int fun(char *in) {
    char *t = malloc(1000);
    strcpy(t, in);
    if (isdigit(t[0])) {
        return atoi(t);
    } else {
        t[strlen(t) - 1] = '\0';
        if (t[0] == 'F')
            return fun(t + 2) + 1;
        if (t[0] == 'G') {
            t += 2;
            int l = 0, r = 0, i = 0;
            for (; i < strlen(t); l += (t[i] == '('), r += (t[i] == ')'), i++) {
                if (t[i] == ',' && r == l) {
                    t[i] = '\0';
                    break;
                }
            }
            return fun(t) + fun(t + i + 1);
        }
    }
}
int main() {
    char in[1000] = {};
    scanf("%s", in);
    printf("%d\n", fun(in));
}
