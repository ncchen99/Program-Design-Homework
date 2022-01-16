#include <stdio.h>
void swap(char a[], int h, int s);
void rotate(char a[], char w, int l, int h, int s);               //s=start h=high
void rail_fence_cipher(char a[], int n[], int h, int s, int ln);  //bug here
void caeser_cipher(char a[], int k, int h, int s);
void trithemius_cipher(char a[], int k, int w, int h, int s);  //順w=1反w=-1
void vigenere_cipher(char a[], char c[], int cl, int h, int s);

void first(char a[]);
void second(char a[]);
void third(char a[]);
void forth(char a[]);
void fifth(char a[]);

int main() {
    char old[64];
    int type;
    scanf("%d", &type);
    for (int i = 0; i < 64; ++i) {
        scanf("%c", &old[i]);
        if (old[i] == '\n') i--;
    }
    //char key[5]={'a','b','c','d','e'};
    //vigenere_cipher(old,key,5,19,0);
    //int n[9]={5,1,2,6,9,8,4,3,7};
    //rail_fence_cipher(old,n,9,0,9);
    //rotate(old,'r',11,64,0);
    if (type == 1) first(old);
    if (type == 2) second(old);
    if (type == 3) third(old);
    if (type == 4) forth(old);
    if (type == 5) fifth(old);

    for (int i = 0; i < 64; ++i) {
        printf("%c", old[i]);
    }
    return 0;
}

void swap(char a[], int h, int s) {
    char temp[40];
    for (int i = s; i < h / 2; ++i) {
        temp[i] = a[i];
        a[i] = a[i + h / 2];
    }
    for (int i = s; i < h / 2; ++i) {
        a[i + h / 2] = temp[i];
    }
}

void rotate(char a[], char w, int l, int h, int s) {
    char temp[70];
    if (w == 'l') {
        for (int i = s; i < h; ++i) {
            if (i + l < h)
                temp[i] = a[i + l];
            else
                temp[i] = a[i + l - h + s];
        }
    } else if (w == 'r') {
        for (int i = s; i < h; ++i) {
            if (i - l >= s)
                temp[i] = a[i - l];
            else
                temp[i] = a[i - l - s + h];
        }
    }
    for (int i = s; i < h; ++i) {
        a[i] = temp[i];
    }
}

void rail_fence_cipher(char a[], int n[], int h, int s, int ln) {
    char temp[70];
    char tempch[ln];
    int temps = s;
    while (h - s >= ln) {
        for (int i = 0; i < ln; ++i) {
            tempch[i] = a[s + i];
        }

        for (int i = 0; i < ln; ++i) {
            temp[s + n[i] - 1] = tempch[i];
        }
        s += ln;
    }
    while (h - s > 0) {
        temp[s] = a[s];
        s++;
    }
    s = temps;

    for (int i = s; i < h; ++i) {
        a[i] = temp[i];
    }
}

void caeser_cipher(char a[], int k, int h, int s) {
    for (int i = s; i < h; ++i) {
        if (a[i] >= 'a' && a[i] <= 'z') {
            int temp = (int)a[i] + k;
            if (temp < 'a') {
                temp = 'z' - ('a' - temp + 1);
            }
            if (temp > 'z') {
                temp = temp - 'z' - 1 + 'a';
            }
            a[i] = (char)temp;
        } else if (a[i] >= 'A' && a[i] <= 'Z') {
            int temp = (int)a[i] + k;
            if (temp < 'A') {
                temp = 'Z' - ('A' - temp + 1);
            }
            if (temp > 'Z') {
                temp = temp - 'Z' - 1 + 'A';
            }
            a[i] = (char)temp;
        }
    }
}

void trithemius_cipher(char a[], int k, int w, int h, int s) {
    int alpha_count = 0;
    for (int i = s; i < h; ++i) {
        if (a[i] >= 'a' && a[i] <= 'z') {
            int change = k + alpha_count * w;
            change = change % 26;
            int temp = (int)a[i] + change;
            if (temp < 'a') {
                temp = 'z' - ('a' - temp + 1);
            }
            if (temp > 'z') {
                temp = temp - 'z' - 1 + 'a';
            }
            a[i] = (char)temp;
            alpha_count++;
        } else if (a[i] >= 'A' && a[i] <= 'Z') {
            int change = k + alpha_count * w;
            change = change % 26;
            int temp = (int)a[i] + change;
            if (temp < 'A') {
                temp = 'Z' - ('A' - temp + 1);
            }
            if (temp > 'Z') {
                temp = temp - 'Z' - 1 + 'A';
            }
            a[i] = (char)temp;
            alpha_count++;
        }
    }
}

void vigenere_cipher(char a[], char c[], int cl, int h, int s) {
    for (int i = s, k = 0; i < h; i++) {
        if (a[i] >= 'A' && a[i] <= 'Z') {
            a[i] = (a[i] - 65 + c[(k++ % strlen(c)) % cl] - 97) % 26 + 65;
        } else if (a[i] >= 'a' && a[i] <= 'z') {
            a[i] = (a[i] - 97 + c[(k++ % 32) % strlen(c)] - 97) % 26 + 97;
        }
    }
}
//combination
void first(char a[]) {
    swap(a, 64, 0);
    caeser_cipher(a, 13, 32, 0);
    char key[4] = {'m', 'e', 'o', 'w', '\0'};
    vigenere_cipher(a, key, 4, 64, 32);
    rotate(a, 'l', 3, 64, 0);
}

void second(char a[]) {
    rotate(a, 'r', 11, 64, 0);

    trithemius_cipher(a, 74, 1, 64, 0);

    rotate(a, 'r', 1, 32, 0);

    rotate(a, 'r', 3, 64, 32);

    int key[8] = {4, 3, 1, 2, 7, 6, 5, 8};
    rail_fence_cipher(a, key, 64, 0, 8);
}

void third(char a[]) {
    int key1[4] = {3, 2, 4, 1};
    rail_fence_cipher(a, key1, 64, 0, 4);

    caeser_cipher(a, 8, 32, 0);

    int key2[8] = {1, 8, 4, 3, 6, 5, 7, 2};
    rail_fence_cipher(a, key2, 64, 32, 8);

    swap(a, 64, 0);

    trithemius_cipher(a, 602, -1, 64, 0);

    rotate(a, 'r', 7, 64, 0);
}

void forth(char a[]) {
    char key1[8] = {'v', 'i', 'g', 'e', 'n', 'e', 'r', 'e', '\0'};
    vigenere_cipher(a, key1, 8, 32, 0);
    swap(a, 32, 0);
    trithemius_cipher(a, 3, 1, 32, 0);
    rotate(a, 'l', 24, 64, 32);
    rotate(a, 'r', 19, 64, 0);
}

void fifth(char a[]) {
    int key1[8] = {3, 1, 7, 6, 4, 5, 2, 8};
    rail_fence_cipher(a, key1, 64, 0, 8);
    caeser_cipher(a, 10, 32, 0);
    int key2[4] = {2, 4, 1, 3};
    rail_fence_cipher(a, key2, 64, 32, 4);
    swap(a, 64, 0);
    trithemius_cipher(a, 52, 1, 64, 0);
    rotate(a, 'r', 7, 64, 0);
}