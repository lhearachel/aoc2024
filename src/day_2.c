#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "array.h"
#include "days.h"

static bool is_safe(struct array *report)
{
    bool safe_up = true, safe_down = true;
    for (size_t i = 1; i < report->used; i++) {
        int diff = report->data.ints[i] - report->data.ints[i - 1];
        safe_up   &= diff > 0 && diff < 4;
        safe_down &= diff < 0 && diff > -4;
    }

    return safe_up || safe_down;
}

static bool check_skips(struct array *report)
{
    int skipped = array_remove_i(report, report->used - 1);
    bool safe = is_safe(report);
    for (int i = report->used - 1; i >= 0; i--) {
        int tmp = report->data.ints[i];
        report->data.ints[i] = skipped;
        skipped = tmp;

        safe |= is_safe(report);
    }

    return safe;
}

void day2(void)
{
    char line[256];
    struct array *report = array_new(10, true);
    unsigned int p1 = 0, p2 = 0;

    while (fgets(line, 256, stdin)) {
        char *tok = strtok(line, " \n");
        do {
            array_append_i(report, atoi(tok));
        } while ((tok = strtok(NULL, " \n")));

        bool safe = is_safe(report);
        p1 += safe;
        p2 += safe || check_skips(report);

        array_clear(report, NULL);
    }

    printf("%d\n", p1);
    printf("%d\n", p2);
    array_free(report, NULL);
}
