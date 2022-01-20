#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    char in[10000] = {}, ops[10000] = {};
    gets(in);
    int nums[10000] = {}, nidx = 0, oidx = 0, i = 1;
    char *p = strtok(in, " ");
    while (p != NULL) {
        if (isdigit(p[0])) {
            nums[nidx++] = atoi(p);
            if (ops[oidx - 1] == '*') {
                nums[nidx - 2] = nums[nidx - 2] * nums[nidx - 1];
                nidx--;
                oidx--;
            } else if (ops[oidx - 1] == '/') {
                nums[nidx - 2] = nums[nidx - 2] / nums[nidx - 1];
                nidx--;
                oidx--;
            }
        } else
            ops[oidx++] = p[0];
        p = strtok(NULL, " ");
    }
    while (nidx > i) {
        if (ops[i - 1] == '+')
            nums[i] = nums[i - 1] + nums[i];
        else if (ops[i - 1] == '-')
            nums[i] = nums[i - 1] - nums[i];
        i++;
    }
    printf("%d\n", nums[i - 1]);
}