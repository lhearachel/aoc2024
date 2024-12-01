#include <stdio.h>
#include <stdlib.h>

#include "array.h"
#include "days.h"

static int c(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

void day1(void)
{
    struct array *left = array_new(1000, true);
    struct array *right = array_new(1000, true);

    int l_i, r_i;
    while (scanf("%d   %d", &l_i, &r_i) != EOF) {
        array_append_i(left, l_i);
        array_append_i(right, r_i);
    }

    qsort(left->data.ints, left->used, sizeof(int), c);
    qsort(right->data.ints, left->used, sizeof(int), c);

    int p1 = 0, p2 = 0, count_of = 0, prev_l = -1;
    size_t j = 0;
    for (size_t i = 0; i < left->used; i++) {
        if (prev_l != left->data.ints[i]) count_of = 0;
        while (right->data.ints[j] < left->data.ints[i]) j++;
        while (right->data.ints[j] == left->data.ints[i]) {
            count_of++;
            j++;
        }
        prev_l = left->data.ints[i];

        p1 += abs(left->data.ints[i] - right->data.ints[i]);
        p2 += left->data.ints[i] * count_of;
    }

    array_free(left, NULL);
    array_free(right, NULL);
    free(left);
    free(right);

    printf("%d\n", p1);
    printf("%d\n", p2);
}
