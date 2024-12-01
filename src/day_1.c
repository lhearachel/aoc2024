#include "days.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

static void read(int left[], int right[])
{
    FILE *fin = fopen(INFILE, "r");
    if (fin == NULL) {
        fprintf(stderr, "Cannot open input file\n");
        exit(EXIT_FAILURE);
    }

    char line[32];
    char num[NSIZE + 1] = { 0 };
    for (int i = 0; i < LSIZE; i++) {
        if (fgets(line, sizeof(line), fin) == NULL) {
            fprintf(stderr, "Unexpected EOF on line %d\n", i);
            exit(EXIT_FAILURE);
        }

        strncpy(num, line, NSIZE);
        left[i] = atoi(num);
        strncpy(num, line + NSIZE + 3, NSIZE);
        right[i] = atoi(num);
    }

    fclose(fin);
}

static int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

static int part1(void)
{
    int left[LSIZE], right[LSIZE];
    read(left, right);
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
    read(left, right);

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
