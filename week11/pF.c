#include <stdio.h>
#include <string.h>

void split(char s[], char o[], char t[]) {
    for (int i = 0; i < strlen(s) / 2; i++)
        o[i] = s[i];
    for (int i = strlen(s) / 2; i < strlen(s); i++)
        t[i - strlen(s) / 2] = s[i];
}
void merge(char s[], char o[], char t[]) {
    for (int i = 0; i < strlen(o); i++)
        s[i] = o[i];
    for (int i = strlen(o); i < strlen(o) + strlen(t); i++)
        s[i] = t[i - strlen(o)];
}
void swap(char a[]) {
    char tmp[1024] = {};
    for (int i = 0; i < strlen(a) / 2; i++)
        tmp[i] = a[i];
    for (int i = 0; i < strlen(a) / 2; i++)
        a[i] = a[i + strlen(a) / 2];
    for (int i = strlen(a) / 2; i < strlen(a); i++)
        a[i] = tmp[i - strlen(a) / 2];
}
void rotate(char a[], int n) {
    char tmp[1024];
    strcpy(tmp, a);
    if (n > 0)
        for (int i = 0; i < strlen(a); i++)
            tmp[i] = a[(i + n) % strlen(a)];
    if (n < 0)
        for (int i = 0; i < strlen(a); i++)
            tmp[i] = a[(i + strlen(a) + n) % strlen(a)];
    strcpy(a, tmp);
}
void rail(char a[], int key[], int keylen) {
    char tmp[1024] = {};
    for (int i = 0; i < strlen(a) - (strlen(a) % keylen); i++)
        tmp[key[i % keylen] - 1 + (i / keylen) * keylen] = a[i];
    for (int i = strlen(a) - (strlen(a) % keylen); i < strlen(a); i++)
        tmp[i] = a[i];
    strcpy(a, tmp);
}
void caesar(char a[], int n) {
    char tmp[1024] = {};
    for (int i = 0; i < strlen(a); i++)
        tmp[i] = ('a' <= a[i] && a[i] <= 'z' ? ((a[i] + (n % 26 < 0 ? 26 + n % 26 : n % 26) - 'a') % 26) + 'a' : ('A' <= a[i] && a[i] <= 'Z' ? (a[i] + (n % 26 < 0 ? 26 + n % 26 : n % 26) - 'A') % 26 + 'A' : a[i]));
    strcpy(a, tmp);
}
void trithemius(char a[], char g, int r) {
    int s = (g == 'a' ? 1 : -1);
    if (r >= 0)
        r %= 26;
    else
        r = r % 26 + 26;
    for (int i = 0; i < strlen(a); i++) {
        char c = a[i];
        if ('a' <= c && c <= 'z') {
            a[i] = (c - 'a' + r) % 26 + 'a';
            r += s;
            if (r < 0)
                r += 26;
            r %= 26;
        }
        if ('A' <= c && c <= 'Z') {
            a[i] = (c - 'A' + r) % 26 + 'A';
            r += s;
            if (r < 0)
                r += 26;
            r %= 26;
        }
    }
}
void vige(char a[], char k[]) {
    int kl = strlen(k), n = 0;
    for (int i = 0; i < strlen(a); i++) {
        char c = a[i];
        if ('A' <= c && c <= 'Z') {
            a[i] = (c + (k[(n++ % kl)] - 'a') - 'A') % 26 + 'A';
        }
        if ('a' <= c && c <= 'z')
            a[i] = (c + (k[(n++ % kl)] - 'a') - 'a') % 26 + 'a';
    }
}
int main() {
    char s[1024] = {};
    int p;
    scanf("%d\n", &p);
    fgets(s, 1023, stdin);
    s[strlen(s) - 1] = '\0';

    if (p == 1) {
        swap(s);
        char o[1024] = {}, t[1024] = {};
        split(s, o, t);
        caesar(o, 13);
        vige(t, "meow");
        merge(s, o, t);
        rotate(s, 3);
    }
    if (p == 2) {
        rotate(s, -11);
        trithemius(s, 'a', 74);
        char o[1024] = {}, t[1024] = {};
        split(s, o, t);
        rotate(o, -1);
        rotate(t, -3);
        merge(s, o, t);
        int tmp[] = {4, 3, 1, 2, 7, 6, 5, 8};
        rail(s, tmp, 8);
    }
    if (p == 3) {
        int tmp[] = {3, 2, 4, 1};
        rail(s, tmp, 4);
        char o[1024] = {}, t[1024] = {};
        split(s, o, t);
        caesar(o, 8);
        int tmp2[] = {1, 8, 4, 3, 6, 5, 7, 2};
        rail(t, tmp2, 8);
        merge(s, o, t);
        swap(s);
        trithemius(s, 'd', 602);
        rotate(s, -7);
    }
    if (p == 4) {
        char o[1024] = {}, t[1024] = {};
        split(s, o, t);
        vige(o, "vigenere");
        swap(o);
        trithemius(o, 'a', 3);
        rotate(t, 24);
        merge(s, o, t);
        rotate(s, -19);
    }
    if (p == 5) {
        int tmp[] = {3, 1, 7, 6, 4, 5, 2, 8};
        rail(s, tmp, 8);
        char o[1024] = {}, t[1024] = {};
        split(s, o, t);
        caesar(o, 10);
        int tmp2[] = {2, 4, 1, 3};
        rail(t, tmp2, 4);
        merge(s, o, t);
        swap(s);
        trithemius(s, 'a', 52);
        rotate(s, -7);
    }
    printf("%s\n", s);
    return 0;
}
