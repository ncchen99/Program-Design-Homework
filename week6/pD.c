#include <stdio.h>
#include <stdlib.h>
#define f(use, n, a)                    \
    for (int use = 0; use < n; use++) { \
        a;                              \
    }

//            .-'"""'-.
//       ,____|_______|____,
//        '._____________.'  REACH FOR
//            |.-- --.|      THE SKY!
//            |(o) (o)|
//           (|       |)
//            |   U   |
//  __        | .___. |    YOU'RE MY
// /|||       |       |     FAVORITE
// ||||       :       :      DEPUTY!
// |  |/)      `.___.'
//  \  /       __) (__
//   \/\      /\ \ / /\
//    \ \    /\ \ ^ / /\    THERE'S A
//     \ \  / |  |0_/\_ \    SNAKE IN
//      \ \/ /|  | \  /\ \    MY BOOT!
//       \  / |  |0//\\ \ \
//        \/  | /   \ |  \ \
//            |/ .-. \|  / /
//         .-'|-( ~ )-| / /   HI!
//         \  |--`-'--|/ /   MY NAME'S WOODY!
//          \ |       | /
//           \|   |   |/
//            |   |   |
//            |   |   |     HOWDY PARDNER!
//            |   |   |
//            |   |   |
//            |   |   |
//            |___|___|     YEEEHAH COWBOY!
//           `|---|---|'
//           *|   |   |*
//            |_._|_._|
//           /'  /|\  '\    SOMEONE POISONED
//      jgs /   /^ ^\   \    THE WATERHOLE!
//         /__.'     `.__\


int main() {
    int h, s = 0;
    scanf("%d", &h);

    f(i, h - 1, f(j, h - i - 1, printf(" "));
      f(k, i * 2 + 1, printf("%c", k & 1 ? 88 : 79));
      printf("\n"));
    f(i, h * 2 - 1, printf("O"));
    printf("\n");
}