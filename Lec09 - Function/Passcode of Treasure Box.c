#include <stdio.h>
int box[20002] = {0};
int boxGen() {
    box[1] = 1;
    for (int i = 2; i < 10000; i++) {
        if (i & 1)
            box[i] = box[i - 1] + box[i + 1];
        else {
            box[i] = box[i / 2];
            box[2 + i] = box[i / 2 + 1];
        }
    }
}
int main() {
    int n;
    boxGen();
    scanf("%d", &n);
    printf("%d", box[n]);
}