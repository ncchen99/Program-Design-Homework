#include <stdio.h>
#include <string.h>

char *reference(char author[], char title[], char conference[], char location[], char date[], char ppdoi[]);

int main() {
    char author[100], title[150], conference[150], location[30], date[5], ppdoi[60];
    scanf("%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]", author, title, conference, location, date, ppdoi);
    printf("%s", reference(author, title, conference, location, date, ppdoi));
    return 0;
}

// In case you don't know how to return a string, I already wrote that part. Just insert your thought between them.
char *reference(char author[], char title[], char conference[], char location[], char date[], char ppdoi[]) {
    static char result[300] = "";
    strcat(result, author);
    strcat(result, ", \"");
    strcat(result, title);
    strcat(result, ",\" ");
    strcat(result, conference);
    strcat(result, ", ");
    strcat(result, location);
    strcat(result, ", ");
    strcat(result, date);
    strcat(result, ", ");
    strcat(result, ppdoi);
    strcat(result, ".");
    return result;
}