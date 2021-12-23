

int *poly(int *f, int *s, int *x) {
    int z = 0;
    if (!f) f = &z;
    if (!s) s = &z;
    if (!x) x = &z;
    int t = malloc(sizeof(int));
    t = ((*f) * (*f) * (*f) + (*s) * (*s) + (*x));
    return &t;
}