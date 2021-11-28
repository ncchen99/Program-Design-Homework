#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(char *a, char *b) {
    return strcmp(a, b);
}

int main() {
    char allStudents[35][101];
    int n, namelen;
    scanf("%d", &n);
    char transferStudentName[101];
    scanf("%d %s", &namelen, transferStudentName);
    strcpy(allStudents[0], transferStudentName);
    for (int i = 1; i <= n; i++) {
        scanf("%d %s", &namelen, allStudents[i]);
    }

    qsort(allStudents, n + 1, sizeof(allStudents[0]), cmp);

    for (int i = 0; i < n + 1; i++)
        if (!strcmp(allStudents[i], transferStudentName))
            printf("%d\n", i + 1);
}