#include <stdio.h>

int main() {
    char c, g;
    int r = 1, s;
    scanf("%d\n%c\n", &r, &g);
    s = (g == 'a' ? 1 : -1);
    if (r >= 0)
        r %= 26;
    else
        r = r % 26 + 26;
    while ((c = getchar()) != '\n') {
        // printf("r: %d\n", r);
        if ('a' <= c && c <= 'z') {
            printf("%c", (c - 'a' + r) % 26 + 'a');
            r += s;
            if (r < 0)
                r += 26;
            r %= 26;
            // printf("r: %d\n", r);
        } else if ('A' <= c && c <= 'Z') {
            printf("%c", (c - 'A' + r) % 26 + 'A');
            r += s;
            if (r < 0)
                r += 26;
            r %= 26;
        } else
            printf("%c", c);
    }
    printf("\n");
    return 0;
}
