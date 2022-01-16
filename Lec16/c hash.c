#include <search.h>
#include <stdio.h>
#include <stdlib.h>

static char *companies[] = {"Intel", "AMD", "ARM", "Apple",
                            "Marvell", "Qualcomm", "IBM", "Nvidia"};

static char *uarch[] = {"Willow Cove", "Zen 3", "A78", "A14",
                        "ThunderX2", "Kryo", "z15", "Ampere"};

int main(void) {
    ENTRY e;
    ENTRY *ep;

    const size_t capacity = sizeof companies / sizeof companies[0];
    hcreate(capacity);

    for (size_t i = 0; i < capacity - 2; i++) {
        e.key = companies[i];
        e.data = (void *)uarch[i];

        ep = hsearch(e, ENTER);

        if (ep == NULL) {
            fprintf(stderr, "entry failed\n");
            exit(EXIT_FAILURE);
        }
    }

    e.key = "Intel";
    ep = hsearch(e, FIND);
    printf("%s -> %s\n", e.key, (char *)ep->data);

    hdestroy();
    exit(EXIT_SUCCESS);
}