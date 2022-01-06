#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char *protocol;
    char *host;
    char *pathname;
    char *search;
    char *hash;
    int port;
} Location;

Location *parse_url(char *url);

int main() {
    char url[500] = "";
    fgets(url, 500, stdin);  // Get url string
    Location *l = parse_url(url);
    printf("Location {\n  protocol: %s,\n  host: %s,\n", l->protocol, l->host);
    if (l->port)
        printf("  port: %d,\n", l->port);
    else
        printf("  port: (default),\n");
    printf("  pathname: /%s,\n  search: ?%s,\n  hash: #%s,\n}\n", l->pathname, l->search, l->hash);
    return 0;
}

Location *parse_url(char *url) {
    url[strlen(url) - 1] = '\0';
    static char protocol[300] = {0}, host[300] = {0}, pathname[300] = {0}, search[300] = {0}, hash[300] = {0};
    int port = 0, c = 0;
    char tmp[1000];
    strcpy(tmp, url);
    char tokens[120] = ":?#/";
    char *t = strtok(tmp, tokens), *fpn = NULL;
    while (t != NULL) {
        // printf("%s\n", t);
        if (strstr(url, t) == url)
            strcpy(protocol, t);
        if ((strstr(url, t) - 1)[0] == '/' && c == 0)
            strcpy(host, t);
        if ((strstr(url, t) - 1)[0] == ':') {
            port = atoi(t);
        }
        if (strstr(url, t) != url && (strstr(url, t) - 1)[0] == '/' && c == 1) {
            fpn = t;
            // printf("c1 : %s\n", t);
            tokens[3] = '\0';
        }
        if (strstr(url, t) != url && (strstr(url, t) - 1)[0] == '/' && c++ == 2) {
            // printf("c2 : %s\nfpn:%s\n", t, fpn);
            strcpy(pathname, fpn);
            fpn = NULL;
            strcat(pathname, "/");
            strcat(pathname, t);
        }
        if ((strstr(url, t) - 1)[0] == '?') {
            if (fpn != NULL) {
                strcpy(pathname, fpn);
                fpn = NULL;
            }
            strcpy(search, t);
        }
        if ((strstr(url, t) - 1)[0] == '#') {
            if (fpn != NULL) {
                strcpy(pathname, fpn);
                fpn = NULL;
            }

            strcpy(hash, t);
        }
        t = strtok(NULL, tokens);
    }
    static Location ans;
    ans.protocol = protocol;
    ans.host = host;
    ans.pathname = pathname;
    ans.search = search;
    ans.hash = hash;
    ans.port = port;
    return &ans;
}