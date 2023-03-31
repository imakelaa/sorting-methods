#include "batcher.h"

#include "stats.h"

#include <stdio.h>

//BATCHER ALGORITHM

void comparator(Stats *stats, uint32_t *arr, uint32_t x, uint32_t y) {
    if ((cmp(stats, arr[x], arr[y])) == 1) {
        swap(stats, &arr[x], &arr[y]);
    }
}

uint32_t bit_length(uint32_t n) {
    uint32_t len = 0;
    while (n != 0) {
        n >>= 1;
        len++;
    }
    return len;
}

void batcher_sort(Stats *stats, uint32_t *arr, uint32_t n) {
    if (n == 0) {
        return;
    }

    uint32_t t = bit_length(n);
    uint32_t p = 1 << (t - 1);
    while (p > 0) {
        uint32_t q = 1 << (t - 1);
        uint32_t r = 0;
        uint32_t d = p;
        while (d > 0) {
            for (uint32_t i = 0; i < (n - d); i++) {
                if ((i & p) == r) {
                    comparator(stats, arr, i, i + d);
                }
            }
            d = q - p;
            q >>= 1;
            r = p;
        }
        p >>= 1;
    }
}
