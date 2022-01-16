#include <stdio.h>
#include <string.h>
int main() {
    int n;
    char r[8] = "MDCLXVI";
    int u[8] = {1000, 500, 100, 50, 10, 5, 1};
    scanf("%d", &n);
    for (int i = 0; i < 7; n %= u[i], i += 2) {
        if (n / u[i] == 4)
            printf("%c%c", r[i], r[i - 1]);
        else if (n / u[i] == 9)
            printf("%c%c", r[i], r[i - 2]);
        else {
            if (n / u[i] >= 5) printf("%c", r[i - 1]);
            for (int j = 0; j < (n / u[i]) % 5; j++) printf("%c", r[i]);
        }
    }
}