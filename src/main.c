#include <stdio.h>
#include <stdlib.h>

#include "days.h"

static const day_func day_funcs[] = {
    [0] = NULL,
    [1] = day1,
};

int main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "missing args; usage: aoc2024 <day>\n");
        exit(EXIT_FAILURE);
    }

    day_funcs[atoi(argv[1])]();
    exit(EXIT_SUCCESS);
}
