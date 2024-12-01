#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "days.h"
#include "io.h"

// #define TEST

#ifdef TEST
#define INFILE "data/day1_test.in"
#define LSIZE  6
#define NSIZE  1
#else
#define INFILE "data/day1.in"
#define LSIZE  1000
#define NSIZE  5
#endif

static int part1(void);
static int part2(void);

int day1(int part)
{
    return part == 1 ? part1() : part2();
}

struct lists {
    int *left;
    int *right;
};

static void load_line(const char *line, const int i, void *cb_data)
{
    struct lists *lists = cb_data;
    char num[NSIZE + 1] = { 0 };

    strncpy(num, line, NSIZE);
    lists->left[i] = atoi(num);
    strncpy(num, line + NSIZE + 3, NSIZE);
    lists->right[i] = atoi(num);
}

static int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

static int part1(void)
{
    int left[LSIZE], right[LSIZE];
    struct lists lists = { left, right };
    load_data(INFILE, &lists, load_line);
    qsort(left, LSIZE, sizeof(int), compare);
    qsort(right, LSIZE, sizeof(int), compare);

    int sum = 0;
    for (int i = 0; i < LSIZE; i++) {
        sum = sum + abs(left[i] - right[i]);
    }

    return sum;
}

static int part2(void)
{
    int left[LSIZE], right[LSIZE];
    struct lists lists = { left, right };
    load_data(INFILE, &lists, load_line);

    int sum = 0;
    for (int i = 0; i < LSIZE; i++) {
        int count_of = 0;
        for (int j = 0; j < LSIZE; j++) {
            if (right[j] == left[i]) count_of++;
        }
        sum = sum + (left[i] * count_of);
    }

    return sum;
}
