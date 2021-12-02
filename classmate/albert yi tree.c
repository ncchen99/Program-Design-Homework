#include <math.h>
#include <stdio.h>
#define n 5000
int tree[n];
int order;
int total;
int treecheck[n] = {0};
int preind = 1;
int inind = 1;
int posind = 1;

void preorder() {
    if (treecheck[preind - 1] == 0) {
        printf("%d ", tree[preind - 1]);
        // printf(",the current preind is %d\n", preind)
        treecheck[preind - 1] = 1;
        if (preind * 2 <= total) {
            preind *= 2;
        } else if (preind % 2 == 0 && (preind + 1) <= total) {
            preind += 1;
        }
    } else {
        if (preind % 2 == 1 && preind != 1 || preind == total) {
            preind /= 2;
        } else {
            if (treecheck[preind] == 0) {
                preind++;
            } else {
                return;
            }
        }
    }
    preorder();
}

void inorder() {
    if (treecheck[inind - 1] == 0 && treecheck[inind * 2 - 1] == 1 || treecheck[inind - 1] == 0 && tree[inind * 2 - 1] == 0 && tree[inind - 1] != 0) {
        printf("%d ", tree[inind - 1]);
        // printf(",the current inind is %d\n", inind)
        treecheck[inind - 1] = 1;
        if (inind != 1 && tree[inind * 2] == 0) {
            inind /= 2;
        } else {
            inind = (inind * 2) + 1;
        }
        // printf("the inind here is %d\n", inind);
    } else {
        if (inind % 2 == 1 && inind != 1 && treecheck[inind * 2 - 1] == 1 || inind == total) {
            inind /= 2;
        } else {
            if (treecheck[(inind * 2 - 1)] == 0) {
                inind = inind * 2;
                // printf("the inind here is %d\n", inind);
            } else if (treecheck[inind / 2 - 1] == 0) {
                inind = (inind / 2);
                // printf("the inind here is %d\n", inind);
            } else {
                // printf("the inind here is hello %d\n", inind);
                return;
            }
        }
    }
    inorder();
}

void postorder() {
    if (treecheck[posind - 1] == 0 && treecheck[posind * 2 - 1] == 1 || treecheck[posind - 1] == 0 && tree[posind * 2 - 1] == 0 && tree[posind - 1] != 0) {
        // printf("%d ", tree[inind-1]);
        treecheck[posind - 1] = 1;
        if (posind % 2 == 0 && treecheck[posind] == 0 && tree[posind] != 0) {
            posind++;
        } else {
            posind /= 2;
        }
        // printf("the inind here is %d\n", inind);
    } else {
        if (posind % 2 == 1 && treecheck[posind * 2 - 1] == 0 && tree[posind * 2 - 1] != 0) {
            posind *= 2;
            // printf("the inind here is %d\n", inind);
        } else {
            // printf("the inind here is hello %d\n", inind);
            return;
        }
    }
    postorder();
}

int main() {
    scanf("%d%d", &order, &total);
    for (int i = 0; i < total; ++i) {
        scanf("%d", &tree[i]);
    }
    for (int i = 0; inind * 2 < total; ++i) {
        inind *= 2;
    }
    for (int i = 0; posind * 2 < total; ++i) {
        posind *= 2;
        posind += 1;
    }
    switch (order) {
        case 0:
            preorder();
            break;
        case 1:
            inorder();
            break;
        case 2:
            postorder();
            break;
    }
    return 0;
}