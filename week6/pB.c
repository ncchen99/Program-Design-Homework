#include <stdio.h>
#include <stdlib.h>
#define fi(n) for (int i = 0; i < n; i++)
#define fii(n) for (int ii = 0; ii < n; ii++)

//           _.._        ,------------.
//        ,'      `.    ( 觀世input霎👨‍💻 )
//       /  __) __` \    `-,----------'
//      (  (`-`(-')  ) _.-'
//      /)  \  = /  (
//     /'    |--' .  \
//    (  ,---|  `-.)__`
//     )(  `-.,--'   _`-.
//    '/,'          (  Uu",
//     (_       ,    `/,-' )
//     `.__,  : `-'/  /`--'
//       |     `--'  |
//       `   `-._   /
//        \        (
//        /\ .      \.
//       / |` \     ,-\
//      /  \| .)   /   \
//     ( ,'|\    ,'     :
//     | \,`.`--"/      }
//     `,'    \  |,'    /
//    / "-._   `-/      |
//    "-.   "-.,'|     ;
//   /        _/["---'""]
//  :        /  |"-     '
//  '           |      /
//              `      |
int main() {
    int t;
    scanf("%d", &t);
    int all = 0;
    fi(t) {
        int r = 0;
        fii(3) {
            int a, b;
            scanf("%d%d", &a, &b);
            r += (a > b ? 1 : (a == b ? 0 : -1));
        }
        printf((r == 0 ? "Tie\n" : (r < 0 ? "Lose\n" : "Win\n")));
        if (r > 0) all++;
    }
    printf("%.2f%%", (float)all / t * 100);
}