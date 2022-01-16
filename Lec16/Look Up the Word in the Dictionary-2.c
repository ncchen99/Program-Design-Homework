#include <search.h>
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

int search(dict_t arr[], char target[]) {
    ENTRY e;
    hcreate(10);
    for (size_t i = 0; i < 10; i++) {
        e.key = arr[i].word;
        e.data = (void *)(&arr[i].page);
        hsearch(e, ENTER);
    }
    e.key = target;
    return (hsearch(e, FIND)) ? *(int *)(hsearch(e, FIND)->data) : 0;
}