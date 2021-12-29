int *report_card(int *s) {
    static int *S;
    // s = &score[0]
    int *p, length = 0;
    for (p = s; *p != -1; p++) {
        length++;  // length of score array
    }
    // now p is the address stores -1
    int *q[1001], a[1001] = {};
    // a[length] is used to distinguish whether the score is over 60 or not
    for (int i = 0; i < length; i++) {
        q[i] = s + i;
        a[i] = 0;
        if (*q[i] >= 60)
            a[i] = 1;
    }
    // for (int i = 0; i < length; i++) {
    //     printf("%d ", a[i]);
    // }
    // printf("\n");
    int max1 = 0, max2 = 0, *comp, *initial;

    comp = s;
    initial = s;
    // initial = &score[0]
    // s stores the address of first section with integers >= 60 , max1 is the length of the section
    // comp stores the address of following sections with integers >= 60 , max2 is the length of the section
    // sum1 represent the sum start adding from s
    // sum2 represent the sum start adding from comp
    int i;
    for (i = 0; i < length; i++) {
        if (a[i] == 0)
            continue;
        s = initial + i;
        while (a[i] != 0) {
            max1++;
            // printf("max1:%d\n", max1);
            i++;
        }
        break;
    }
    i++;
    while (i <= length) {
        for (i; i < length; i++) {
            if (a[i] == 0)
                continue;
            comp = initial + i;
            while (a[i] != 0) {
                max2++;
                // printf("max2:%d\n", max2);
                i++;
            }
            break;
        }
        // printf("max1:%d max2:%d\n", max1, max2);
        if (max2 > max1) {
            s = comp;
            max1 = max2;
        } else if (max2 == max1) {
            int sum1 = 0, sum2 = 0;
            for (int *j = s; *j >= 60; j++)
                sum1 += *j;
            for (int *j = comp; *j >= 60; j++)
                sum2 += *j;
            if (sum2 > sum1)
                s = comp;
            // printf("sum1:%d sum2:%d\n", sum1, sum2);
        }
        max2 = 0;
        i++;
    }
    S = s;
    while (*s >= 60) {
        s++;
    }
    *s = -1;
    // for (int i = 0; i < 10; i++) {
    //     printf("%d ", S[i]);
    // }
    return S;
}