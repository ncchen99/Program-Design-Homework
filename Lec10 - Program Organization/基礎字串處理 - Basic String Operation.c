#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    char s[2005] = {0};
    fgets(s, 2000, stdin);
    s[strlen(s) - 1] = '\0';
    int t;
    scanf("%d\n", &t);
    while (t--) {
        char c[1034] = {};
        scanf("%s", c);
        if (!strcmp(c, "REVERSE")) {
            char tmp[2005] = {};
            for (int i = 0; i < strlen(s); i++)
                tmp[i] = s[strlen(s) - i - 1];
            strcpy(s, tmp);
        }
        if (!strcmp(c, "TO_LOWER")) {
            for (int i = 0; i < strlen(s); i++)
                if (s[i] >= 'A' && s[i] <= 'Z')
                    s[i] = s[i] - 'A' + 'a';
        }
        if (!strcmp(c, "TO_UPPER")) {
            for (int i = 0; i < strlen(s); i++)
                if (s[i] >= 'a' && s[i] <= 'z')
                    s[i] = s[i] - 'a' + 'A';
        }
        if (!strcmp(c, "REMOVE")) {
            char tar;
            scanf("%c%c", &tar, &tar);
            char tmp[2005] = {};
            for (int i = 0, j = 0; i < strlen(s); i++)
                if (s[i] != tar)
                    tmp[j++] = s[i];
            strcpy(s, tmp);
        }
        if (!strcmp(c, "COMPRESS")) {
            char tmp[8192] = {};
            for (int i = 0, j = 0; i < strlen(s); i++) {
                int tt = i;
                while (s[tt] == s[tt + 1])
                    tt++;
                tmp[j++] = '-';
                tmp[j++] = s[i];
                char ttt[111];
                sprintf(ttt, "%d", tt - i + 1);

                for (int k = 0; k < strlen(ttt); k++)
                    tmp[j++] = ttt[k];
                i = tt;
            }
            strcpy(s, tmp);
        }
        getchar();
        printf("%s\n", s);
    }
    return 0;
}
