#include <stdio.h>
#include <stdlib.h>

struct node {
    int id;
    struct node *next;
};

struct node *read_data(int *size);  // TODO: implement this function

void print_data(struct node *adj, int size) {
    if (!adj)
        return;
    for (int i = 0; i < size; ++i) {
        printf("%d -> ", adj[i].id);
        for (struct node *ptr = adj[i].next; ptr != NULL; ptr = ptr->next)
            printf("%d ", ptr->id);
        putchar('\n');
    }
}

void free_data(struct node *adj, int size) {
    if (!adj)
        return;
    for (int i = 0; i < size; ++i) {
        struct node *ptr = adj[i].next;
        while (ptr) {
            adj[i].next = ptr->next;
            free(ptr);
            ptr = adj[i].next;
        }
    }
    free(adj);
}

int main() {
    int size;
    struct node *adj = read_data(&size);
    if (!adj) {
        fprintf(stderr, "Error allocating memory.");
        exit(1);
    }
    print_data(adj, size);
    free_data(adj, size);
    return 0;
}

int cmp(struct node *a, struct node *b) {
    return a->id - b->id;
}

struct node *read_data(int *size) {
    struct node *mat = malloc(1005);
    int i = 0;
    for (i = 0; scanf("%d ->", &(mat[i].id)) != EOF; i++) {
        int j, tmp;
        struct node *now = &mat[i];
        scanf("%d", &tmp);
        for (j = 0; tmp != 0; j++) {
            now->next = malloc(sizeof(struct node));
            now = now->next;
            now->id = tmp;
            scanf("%d", &tmp);
        }
        now->next = NULL;
    }
    qsort(mat, i, sizeof(mat[0]), cmp);
    *size = i;
    return mat;
}

/*
5 -> 5 6 8 0
2 -> 36 98 555 0
1 -> 0
88 -> 56 777 0
*/