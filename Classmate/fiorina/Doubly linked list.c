#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data;
    struct Node* prev;
    struct Node* next;
} node;

node* InsertNode(node* head, char data, int pos);
node* DeleteNode(node* head, int pos);
void PrintList(node* head);
void NumOfOccuur(node* head, char data);
void MaxNumOfOccur(node* head);
void SearchWord(node* head, char* word);

int main() {
    node* head = NULL;
    char in, cmd[100] = "";
    int pos = 0;
    while (scanf("%s", cmd) != EOF) {
        if (strcmp(cmd, "InsertNode") == 0) {
            scanf(" %c %d\n", &in, &pos);
            head = InsertNode(head, in, pos);
        }
        if (strcmp(cmd, "PrintList") == 0) {
            PrintList(head);
        }
    }
}

node* InsertNode(node* head, char data, int pos) {
    if (32 > data || data > 126) {
        printf("Insert wrong data\n");
        return head;
    }
    if (head == NULL && pos != 0) {
        printf("Insert wrong position\n");
        return head;
    }
    node *now = head, *pre = head;
    int npos = 0;
    while (npos < pos) {
        if (now == NULL) {
            printf("Insert wrong position\n");
            return head;
        }
        pre = now;
        now = now->next;
        npos++;
    }
    if (now == NULL) {
        now = malloc(sizeof(node));
        now->data = data;
        if (pos != 0) {
            pre->next = now;
            now->prev = pre;
            return head;
        }
        return now;
    } else {
        node* new = malloc(sizeof(node));
        new->data = data;
        new->prev = now->prev;
        new->next = now;
        now->prev = new;
        if (pos != 0) {
            new->prev->next = new;
            return head;
        }
        return new;
    }
}

void PrintList(node* head) {
    node* now = head;
    int pos = 0;
    while (now != NULL) {
        printf("%c ", now->data);
        // Debug: printf("pos: %d, data: %c, nowAddr:%p, prevAddr: %p, nextAddr: %p\n", pos++, now->data, now, now->prev, now->next);
        now = now->next;
    }
}