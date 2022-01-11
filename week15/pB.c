#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 10

typedef struct dict_t_struct {
    char word[10];
    int page;
} dict_t;

int search(dict_t arr[], char target[]);

int main() {
    dict_t dictionary[N];
    char targetWord[10];

    for (int i = 0; i < N; i++)
        scanf("%s %d\n", dictionary[i].word, &dictionary[i].page);

    scanf("%s", targetWord);
    int targetPage = search(dictionary, targetWord);
    printf("%d", targetPage);
    return 0;
}

int str_to_int(char *s) {
    int a = 0;
    for (int i = 0; i < strlen(s); i++) {
        a += s[i] - 'a';
        a *= 3;
    }
    return a;
}

int search(dict_t arr[], char target[]) {
    unsigned char *real_dict = malloc(60000000);
    for (int i = 0; i < N; i++)
        real_dict[str_to_int(arr[i].word)] = (char)arr[i].page;
    return real_dict[str_to_int(target)];
}