#include <stdio.h>

void swap(char chch[], int start, int end);
void rotate(char chch[], int direction, int length, int start, int end);
void rail_fence_cipher(char chch[], int length, int code[], int start, int end);
void caesar_cipher(char chch[], int code, int start, int end);
void trithemius_cipher(char chch[], int code, int direction, int start, int end);
void vigenere_cipher(char chch[], char code[], int length, int start, int end);
void print(char chch[]);

int main() {
    int way;
    scanf("%d", &way);
    char chch[64];
    int i = 0;
    scanf("%c", &chch[0]);
    for (int i = 0; i < 64; i++) {
        scanf("%c", &chch[i]);
    }
    if (way == 1) {
        swap(chch, 0, 64);
        caesar_cipher(chch, 13, 0, 32);
        char code[] = "meow\0";
        vigenere_cipher(chch, code, 4, 32, 64);
        rotate(chch, 0, 3, 0, 64);
    } else if (way == 2) {
        rotate(chch, 1, 11, 0, 64);
        trithemius_cipher(chch, 74, 1, 0, 64);
        rotate(chch, 1, 1, 0, 32);
        rotate(chch, 1, 3, 32, 64);
        int code[] = {4, 3, 1, 2, 7, 6, 5, 8};
        rail_fence_cipher(chch, 8, code, 0, 64);
    } else if (way == 3) {
        int code[] = {3, 2, 4, 1};
        rail_fence_cipher(chch, 4, code, 0, 64);
        caesar_cipher(chch, 8, 0, 32);
        int code2[] = {1, 8, 4, 3, 6, 5, 7, 2};
        rail_fence_cipher(chch, 8, code2, 32, 64);
        swap(chch, 0, 64);
        trithemius_cipher(chch, 602, 0, 0, 64);
        rotate(chch, 1, 7, 0, 64);
    } else if (way == 4) {
        char code[] = "vigenere\0";
        vigenere_cipher(chch, code, 8, 0, 32);
        swap(chch, 0, 32);
        trithemius_cipher(chch, 3, 1, 0, 32);
        rotate(chch, 0, 24, 32, 64);
        rotate(chch, 1, 19, 0, 64);
    } else {
        int code[] = {3, 1, 7, 6, 4, 5, 2, 8};
        rail_fence_cipher(chch, 8, code, 0, 64);
        caesar_cipher(chch, 10, 0, 32);
        int code2[] = {2, 4, 1, 3};
        rail_fence_cipher(chch, 4, code2, 32, 64);
        swap(chch, 0, 64);
        trithemius_cipher(chch, 52, 1, 0, 64);
        rotate(chch, 1, 7, 0, 64);
    }
    print(chch);
    return 0;
}

void swap(char chch[], int start, int end) {
    char temp;
    for (int i = start; i < ((start + end) / 2); i++) {
        temp = chch[i];
        chch[i] = chch[((start + end) / 2) + (i % 32)];
        chch[((start + end) / 2) + (i % 32)] = temp;
    }
}
void rotate(char chch[], int direction, int length, int start, int end) {
    char ch[64];
    for (int i = start; i < end; i++) {
        ch[i] = chch[i];
    }
    length %= (end - start);
    if (direction == 0) {
        for (int i = start; i < end; i++) {
            chch[i] = ch[(i + length) % (end - start) + start];
        }
    } else {
        int temp;
        for (int i = start; i < end; i++) {
            temp = i - length;
            while (temp < 0) {
                temp += (end - start);
            }
            chch[i] = ch[temp % (end - start) + start];
        }
    }
}
void rail_fence_cipher(char chch[], int length, int code[], int start, int end) {
    char ch[64];
    for (int i = start; i < end; i++) {
        ch[i] = chch[i];
    }
    for (int i = start; i < end; i++) {
        if (i < length) {
            chch[code[i] - 1] = ch[i];
        } else {
            chch[(i / length * length) + code[i % length] - 1] = ch[i];
        }
    }
}
void caesar_cipher(char chch[], int code, int start, int end) {
    for (int i = start; i < end; i++) {
        if (chch[i] >= 'A' && chch[i] <= 'Z') {
            chch[i] = (chch[i] - 65 + code) % 26 + 65;
        } else if (chch[i] >= 'a' && chch[i] <= 'z') {
            chch[i] = (chch[i] - 97 + code) % 26 + 97;
        }
    }
}
void trithemius_cipher(char chch[], int code, int direction, int start, int end) {
    for (int i = start; i < end; i++) {
        if (chch[i] >= 'A' && chch[i] <= 'Z') {
            chch[i] = (chch[i] - 65 + code) % 26 + 65;
            direction == 0 ? code-- : code++;
        } else if (chch[i] >= 'a' && chch[i] <= 'z') {
            chch[i] = (chch[i] - 97 + code) % 26 + 97;
            direction == 0 ? code-- : code++;
        }
    }
}
void vigenere_cipher(char chch[], char code[], int length, int start, int end) {
    for (int i = start, k = 0; i < end; i++) {
        if (chch[i] >= 'A' && chch[i] <= 'Z') {
            chch[i] = (chch[i] - 65 + code[(k++ % strlen(code)) % length] - 97) % 26 + 65;
        } else if (chch[i] >= 'a' && chch[i] <= 'z') {
            chch[i] = (chch[i] - 97 + code[(k++ % 32) % strlen(code)] - 97) % 26 + 97;
        }
    }
}

void print(char chch[]) {
    for (int i = 0; i < 64; i++) {
        printf("%c", chch[i]);
    }
    printf("\n");
}