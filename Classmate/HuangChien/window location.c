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
    Location *url2 = malloc(10000);
    url2->port = 0;
    char pro[10000] = {0}, host[10000] = {0}, path[10000] = {0}, search[10000] = {0}, hash[10000] = {0};
    int port[10000];
    for (int i = 0;; i++) {  // get protocol
        pro[i] = url[i];
        if (url[i] == ':') {
            pro[i] = '\0';
            url = url + strlen(pro) + 3;
            break;
        }
    }
    for (int j = 0;; j++) {  // get host
        if (url[j] == '\0' || url[j] == '\n') {
            host[j] = '\0';
            url = url + strlen(host) + 1;
            goto END;
            break;
        }
        host[j] = url[j];
        if (url[j] == ':' || url[j] == '/' || url[j] == '#' || url[j] == '?') {
            host[j] = '\0';
            url = url + strlen(host) + 1;
            break;
        }
    }
    if ((url - 1)[0] == ':')
        for (int j = 0;; j++) {  // get port
            if (url[j] == '\0' || url[j] == '\n') {
                port[j] = '\0';
                for (int k = j - 1, i = 1; k >= 0; k--, i *= 10) {
                    url2->port += port[k] * i;
                }
                url = url + j + 1;
                goto END;
            }

            port[j] = url[j] - 48;
            if (url[j] == '/' || url[j] == '#' || url[j] == '?') {
                port[j] = '\0';
                for (int k = j - 1, i = 1; k >= 0; k--, i *= 10) {
                    url2->port += port[k] * i;
                }
                url = url + j + 1;
                break;
            }
        }
    if ((url - 1)[0] == '/')
        for (int j = 0;; j++) {  // get pathname
            if (url[j] == '\0' || url[j] == '\n') {
                path[j] = '\0';
                url = url + strlen(path) + 1;
                goto END;
                break;
            }
            path[j] = url[j];
            if (url[j] == '?' || url[j] == '#') {
                path[j] = '\0';
                url = url + strlen(path) + 1;
                break;
            }
        }
    if ((url - 1)[0] == '?')
        for (int j = 0;; j++) {  // get search
            if (url[j] == '\0' || url[j] == '\n') {
                search[j] = '\0';
                url = url + strlen(search) + 1;
                goto END;
                break;
            }
            search[j] = url[j];
            if (url[j] == '#') {
                search[j] = '\0';
                url = url + strlen(search) + 1;
                break;
            }
        }
    if ((url - 1)[0] == '#')
        for (int j = 0;; j++) {  // get hash
            if (url[j] == '\n' || url[j] == '\0') {
                hash[j] = '\0';
                break;
            }
            hash[j] = url[j];
        }
END:
    url2->protocol = pro;
    url2->host = host;
    url2->pathname = path;
    url2->search = search;
    url2->hash = hash;
    return url2;
}