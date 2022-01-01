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
    static char protocol[300] = {0}, host[300] = {0}, pathname[300] = {0}, search[300] = {0}, hash[300] = {0};
    int port = 0;
    char *i = strstr(url, "://");
    strncpy(protocol, url, i - url);
    i += 3;
    char *i2 = strstr(i, ":");
    if (i2 != NULL) {
        char ports[6] = "";
        strncpy(ports, i2 + 1, strstr(i2, "/") - i2 - 1);
        // ports[strstr(i2, "/") - i2 - 1] = '\0';
        port = atoi(ports);
        strncpy(host, i, i2 - i);
        i2 += strstr(i2, "/") - i2;
        // host[i2 - i] = '\0';
        // printf("i2 - i:%ld, host:%s\n", i2 - i, host);
    } else {
        i2 = ((strstr(i, "/") == NULL ? i + strlen(i) - 1 : strstr(i, "/")));
        strncpy(host, i, i2 - i);
        if (strstr(i, "/") == NULL) goto HDO;
    }
HDO:
    char *i3 = strstr(i2, "?");
    if (i3 != NULL) {
        i3 += 1;
        strncpy(pathname, i2, i3 - i2 - 1);
        char *i4 = strstr(i3, "#");
        if (i4 != NULL) {
            i4 += 1;
            strncpy(search, i3, i4 - i3 - 1);
            char *i5 = url + strlen(url) - 1;
            strncpy(hash, i4, i5 - i4 - 1);
        } else {
            i4 = url + strlen(url) - 1;
            strncpy(search, i3, i4 - i3);
        }
    } else {
        i3 = strstr(i2, "#");
        if (i3 != NULL) {
            i3 += 1;
            strncpy(pathname, i2, i3 - i2 - 1);
            char *i4 = url + strlen(url) - 1;
            strncpy(hash, i3, i4 - i3);
        } else {
            i3 = url + strlen(url) - 1;
            strncpy(pathname, i2, i3 - i2);
        }
    }
HSO:
    // printf("protocol:%s, host:%s, port:%d, pathname:%s, search:%s, hash:%sEND\n", protocol, host, port, pathname, search, hash);
    // printf("0 in protocal:%s", (protocol[strlen(pathname)] == '\0' ? "Y" : "N"));
    if (port == 0 && !strcmp("https", protocol))
        port = 443;

    static Location ans;
    ans.protocol = protocol;
    ans.host = host;
    ans.pathname = &pathname[1];
    ans.search = search;
    ans.hash = hash;
    ans.port = port;
    return &ans;
}
