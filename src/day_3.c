#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "days.h"

static bool is_numeric(char c)
{
    return c >= '0' && c <= '9';
}

static bool is_accepted(char c, int i)
{
    return (i == 0 && c == 'm')
        || (i == 1 && c == 'u')
        || (i == 2 && c == 'l')
        || (i == 0 && c == 'd')
        || (i == 1 && c == 'o')
        || (i == 2 && c == 'n')
        || (i == 3 && c == '\'')
        || (i == 4 && c == 't')
        || (i > 4  && c == ',')
        || (i > 1 && c == '(')
        || (i > 2 && is_numeric(c));
}

void day3(void)
{
    char c, buf[256];
    size_t i = 0;
    bool enabled = true;
    unsigned int o, p;
    unsigned int p1 = 0, p2 = 0;

    while ((c = fgetc(stdin)) != EOF) {
        if (is_accepted(c, i)) {
            buf[i++] = c;
        } else if (c == ')') {
            buf[i++] = c;
            buf[i] = '\0';

            if (strcmp(buf, "do()") == 0) {
                enabled = true;
                goto bufwipe;
            } else if (strcmp(buf, "don't()") == 0) {
                enabled = false;
                goto bufwipe;
            }

            if (sscanf(buf, "mul(%u,%u)", &o, &p) == 2) {
                p1 += (o * p);
                p2 += ((o * p) * enabled);
            }

            goto bufwipe;
        } else {
        bufwipe:
            for (size_t j = 0; j < i; j++) {
                buf[j] = '\0';
            }
            i = 0;
        }
    }

    printf("%d\n", p1);
    printf("%d\n", p2);
}
