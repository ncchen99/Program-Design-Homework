#include <stdio.h>
#define MAX 122
int main() {
    int score[MAX] = {0}, *p = score;
    while (*(p - 1) != -1) {
        scanf("%d", p++);
    }
}