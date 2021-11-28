#include <stdio.h>

int main() {
    int a;
    scanf("%d", &a);
    printf("%d", a / 2 * 2);
    // int 除法會捨棄結果的小數部分 ex: 5 / 2 => 2
}