#include <stdio.h>
#include <stdlib.h>

#include "days.h"

static const day_func day_funcs[] = {
    [0] = NULL,
    [1] = day1,
};

int main(int argc, char *argv[])
{
    if (argc != 3) {
        fprintf(stderr, "missing args; usage: aoc2024 <day> <part>\n");
        exit(EXIT_FAILURE);
    }

    int day = atoi(argv[1]);
    int part = atoi(argv[2]);
    printf("%d\n", day_funcs[day](part));

    exit(EXIT_SUCCESS);
}
