#include <stdio.h>
#include <string.h>

#define ONE_FORWARD "PATA PATA PATA PON"
#define ATTACK "PON PON PATA PON"
#define DEFENCE_BACKWARD "CHAKA CHAKA PATA PON"

int main() {
    int dis, blood;
    scanf("%d %d\n", &dis, &blood);
    char instr[1000000] = {}, cmp[1000] = {};
    int count_valid_instr = 0, count_instr = 0;
    fgets(instr, 1000000, stdin);
    for (int i = 0, j = 0; instr[i] != '\0'; i++) {
        if (instr[i] == '.' || instr[i] == ',' || instr[i] == '\n') {
            count_instr++;
            if (strcmp(cmp, ONE_FORWARD) == 0) {
                count_valid_instr++;
                dis--;
                if (dis <= 0) {
                    printf("NO %d", blood);
                    break;
                }
                if ((count_instr % 10) == 0) {
                    printf("NO %d", blood);
                    break;
                }
            } else if (strcmp(cmp, ATTACK) == 0) {
                count_valid_instr++;
                if (dis <= 3) {
                    blood--;
                }
                if (blood <= 0) {
                    printf("YES %d", count_valid_instr);
                    break;
                }
                if ((count_instr % 10) == 0) {
                    printf("NO %d", blood);
                    break;
                }
            } else if (strcmp(cmp, DEFENCE_BACKWARD) == 0) {
                count_valid_instr++;
                dis++;
            }
            memset(cmp, '\0', 1000);
            cmp[1000] = "";
            j = 0;
            if (instr[i] == '\n') printf("NO %d", blood);
        } else {
            cmp[j++] = instr[i];
        }
    }
    return 0;
}