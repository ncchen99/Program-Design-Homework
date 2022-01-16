#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define GOODS_SIZE 120
#define MAX_ORDER_SIZE 30
#define MAX_NAME_LEN 15

void recovering_order(char *, char **);

char names[GOODS_SIZE][MAX_NAME_LEN] = {
    "aluminum", "ammunition", "orange", "aspirin", "ax",
    "basketball", "zipper", "bell", "blanket", "drum",
    "canvas", "flute", "eraser", "mirror", "comb",
    "eggplant", "diamond", "zucchini", "door", "butter",
    "egg", "dart", "chair", "encyclopedia", "china",
    "fan", "glue", "elevator", "flower", "hat",
    "garlic", "strawberry", "glove", "flour", "ice",
    "ship", "hammer", "fur", "key", "honey",
    "grape", "icecream", "lock", "iron", "ivory",
    "jacket", "oil", "uniform", "kiwi", "pan",
    "helmet", "keyboard", "yoyo", "jet", "knife",
    "tie", "lemon", "xerox", "ink", "mutton",
    "newspaper", "melon", "coconut", "motorcycle", "longan",
    "nail", "rice", "magnet", "peanut", "ointment",
    "oar", "jeans", "nut", "arrow", "oven",
    "jewel", "wool", "noodle", "pencil", "lamp",
    "refrigerator", "needle", "roast", "vest", "yarn",
    "saw", "hamburger", "soap", "glass", "wine",
    "tangerine", "pillow", "umbrella", "zinc", "train",
    "uglifruit", "toast", "underwear", "vanilla", "jeep",
    "unicycle", "vase", "rope", "violin", "warship",
    "volleyball", "water", "yogurt", "submarine", "passionfruit",
    "yacht", "rose", "window", "yolk", "kite",
    "liquor", "xylophone", "toothbrush", "battery", "doll"};

int main(void) {
    char order[500] = "", *result = NULL;
    scanf("%s", order);
    recovering_order(order, &result);
    printf("%s", result);
    free(result);
    return 0;
}
void recovering_order(char *order, char **result) {
    char *p = strtok(order, ":");
    *result = malloc(1000000);
    memset(*result, '\0', 100000);
    int c = 0;
    while (p != NULL) {
        char tmp[120] = {};
        int mlen = 10000, j = 0;

        for (int i = 0; i < GOODS_SIZE; i++) {
            for (char *s = names[i]; s < names[i] + strlen(names[i]) - strlen(p) + 1; s++) {
                if (!strncmp(s, p, strlen(p)) && !strcmp(tmp, "")) {
                    // printf("frist name:%s, startfrom:%s\n", names[i], s);
                    strcpy(tmp, names[i]);
                    mlen = s - names[i];
                } else if (!strncmp(s, p, strlen(p)) && s - names[i] < mlen) {
                    strcpy(tmp, names[i]);
                    mlen = s - names[i];
                } else if (!strncmp(s, p, strlen(p)) && s - names[i] == mlen && (strlen(tmp) > strlen(names[i]) || (strcmp(names[i], tmp) < 0 && strlen(tmp) >= strlen(names[i])))) {
                    // printf("name:%s, startfrom:%s\n", names[i], s);
                    strcpy(tmp, names[i]);
                }
            }
        }

        // printf("j:%d", j);
        // qsort(tmp, j, sizeof(tmp[0]), cmp);
        strcat(*result, (c == 0 ? "" : "+"));
        strcat(*result, tmp);
        // printf("%s", tmp);
        c++;
        p = strtok(NULL, ":");
    }
    return;
}