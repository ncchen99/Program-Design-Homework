#include <stdio.h>
#include <string.h>
#define f(u, s, n, a)             \
    for (int u = s; u < n; u++) { \
        a;                        \
    }
int main() {
    int n;
    char s[10001];
    scanf("%d\n%[^\n]s", &n, s);
    f(i, 0, strlen(s), printf("%c", 'a' <= s[i] && s[i] <= 'z' ? ((s[i] + (n % 26 < 0 ? 26 + n % 26 : n % 26) - 'a') % 26) + 'a' : ('A' <= s[i] && s[i] <= 'Z' ? (s[i] + (n % 26 < 0 ? 26 + n % 26 : n % 26) - 'A') % 26 + 'A' : s[i])));
}