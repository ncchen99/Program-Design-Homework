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
    *result = malloc(100000);
    long long pos, min = 100000;
    int count = 1, count2 = 0;
    char *pch[MAX_ORDER_SIZE];
    pch[0] = strtok(order, ":");
    for (int i = 1; i < MAX_ORDER_SIZE; i++, count++) {
        pch[i] = strtok(NULL, ":");
        if (pch[i] == NULL) break;
    }
    for (int j = 0; j < count; j++) {
        char tem[1000] = {};
        for (int i = 0; i < GOODS_SIZE; i++) {
            char *a = strstr(names[i], pch[j]);
            if (a == NULL) {
                continue;
            } else {
                pos = a - names[i];
                if (pos < min) {
                    min = pos;
                    strcpy(tem, names[i]);
                } else if (pos == min && count2 != 0) {
                    if (strcmp(tem, a) < 0) {
                        for (int k = 0; k < strlen(a); k++)
                            tem[k] = '\0';
                        strcpy(tem, a);
                    }
                }
                count2++;
            }
        }

        strcat(*result, tem);
        if (j + 1 != count)
            strcat(*result, "+");
        count2 = 0;
    }
}