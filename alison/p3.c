#include <stdio.h>

int main() {
    float a;
    scanf("%f", &a);
    printf("%d", (int)a); 
    // 轉成 int 會自動捨去小數部分
}