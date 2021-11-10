#include <stdio.h>
int main() {
    int N, total, S;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {  //n行
        scanf("%d ", &S);          //幾進位
        char temp;
        int digit = 0;            //number
        long long int value = 0;  //
        int count = 0;
        while ((temp = getchar()) != '\n' && temp != EOF) {
            /*
                 排除八進位十六進位前ㄉ開頭(0/0x)  省略~
            */
            count++;
            if (temp == ' ' || (count == 1 && temp == '0') || (count == 2 && (temp == 'x' || temp == 'X')))
                continue;

            if (temp >= '0' && temp <= '9')
                digit = temp - '0';
            else
                digit = temp - 'A' + 10;
            // printf("digit: %d\n", digit);
            if (S == 8) {
                value = (value + digit) << 3;  //八進位則值乘以8(用位移的方式來加快速度)
            } else if (S == 16) {
                value = (value + digit) << 4;  //十六進位值乘以16(同八進位)
            } else {
                value = (value + digit) * S;  //六進位十進位則直接乘以base
            }
        }
        value = value / S;  //在迴圈裡多乘了一次base所以最後要除回來
        total = (total + value) % 1000000007;
    }
    printf("%d", total);
}

/*
8
6 0
8 00
10 0
16 0x0
6 243121245343
8 07346544777
10 999999999
16 0X3B9AC9FF

*/