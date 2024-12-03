#ifndef AOC2024_ARRAY_H
#define AOC2024_ARRAY_H

#include <stdbool.h>
#include <stdlib.h>

typedef void (*free_cb)(void *p);

struct array {
    bool is_int;
    union {
        int *ints;
        void **ptrs;
    } data;

    size_t used;
    size_t size;
};

struct array* array_new(size_t initial, bool is_int);
void array_free(struct array *arr, free_cb cb);
void array_clear(struct array *arr, free_cb cb);

int array_remove_i(struct array *arr, size_t i);

void array_append_i(struct array *arr, int i);
void array_append_d(struct array *arr, void *d);

#endif // AOC2024_ARRAY_H
