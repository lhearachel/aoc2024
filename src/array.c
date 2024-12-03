#include "array.h"

#include <stdlib.h>

struct array* array_new(size_t initial, bool is_int)
{
    struct array *arr = malloc(sizeof(struct array));
    arr->is_int = is_int;
    arr->data.ints = malloc(initial * sizeof(int));
    arr->used = 0;
    arr->size = initial;

    return arr;
}

void array_free(struct array *arr, free_cb cb)
{
    if (!arr->is_int) {
        for (size_t i = 0; i < arr->used; i++) {
            cb(arr->data.ptrs[i]);
        }

        free(arr->data.ptrs);
        arr->data.ptrs = NULL;
    } else {
        free(arr->data.ints);
        arr->data.ints = NULL;
    }

    arr->used = 0;
    arr->size = 0;
}

void array_clear(struct array *arr, free_cb cb)
{
    if (!arr->is_int) {
        for (size_t i = 0; i < arr->used; i++) {
            cb(arr->data.ptrs[i]);
            arr->data.ptrs[i] = NULL;
        }
    } else {
        for (size_t i = 0; i < arr->used; i++) {
            arr->data.ints[i] = 0;
        }
    }

    arr->used = 0;
}

int array_remove_i(struct array *arr, size_t i)
{
    int removed = arr->data.ints[i];
    do {
        arr->data.ints[i] = arr->data.ints[i + 1];
    } while (++i < arr->used - 1);

    arr->used--;
    return removed;
}

void array_append_i(struct array *arr, int i)
{
    if (arr->used == arr->size) {
        arr->size = ((arr->size * 3) / 2 + 8);
        arr->data.ints = realloc(arr->data.ints, arr->size * sizeof(int));
    }

    arr->data.ints[arr->used] = i;
    arr->used++;
}

void array_append_d(struct array *arr, void *d)
{
    if (arr->used == arr->size) {
        arr->size = ((arr->size * 3) / 2 + 8);
        arr->data.ptrs = realloc(arr->data.ptrs, arr->size * sizeof(int));
    }

    arr->data.ptrs[arr->used] = d;
    arr->used++;
}
