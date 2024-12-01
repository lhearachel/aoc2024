#include "io.h"

#include <stdio.h>
#include <stdlib.h>

void load_data(const char *inp, void *cb_data, load_callback cb)
{
    FILE *fin = fopen(inp, "r");
    if (fin == NULL) {
        fprintf(stderr, "Cannot open input file\n");
        exit(EXIT_FAILURE);
    }

    char line[1024];
    for (int i = 0; fgets(line, sizeof(line), fin) != NULL; i++) {
        cb(line, i, cb_data);
    }

    fclose(fin);
}
