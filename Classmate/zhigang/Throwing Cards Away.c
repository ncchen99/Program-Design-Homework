#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    struct node *first = NULL;
    for (int i = n; i >= 1; i--) {
        struct node *new_node;
        new_node = malloc(sizeof(struct node));
        new_node->value = i;
        new_node->next = first;
        first = new_node;
    }

    for (int i = 1; i <= m; i++) {
        printf("%d ", first->value);
        struct node *delete = first;
        first = first->next;
        if (!first)
            break;
        free(delete);
        struct node *curr = first;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        struct node *new_node;
        new_node = malloc(sizeof(struct node));
        new_node->value = first->value;
        new_node->next = NULL;
        curr->next = new_node;
        first = first->next;
    }
    return 0;
}