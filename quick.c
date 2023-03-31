#include "quick.h"

#include "stats.h"

#include <stdio.h>

//QUICK SORT ALGORITHM

int partition(Stats *stats, uint32_t *arr, uint32_t lo, uint32_t hi) { 
    uint32_t i = lo - 1;
    for (uint32_t j = lo; j < hi; j++) {
        if (cmp(stats, arr[j - 1], arr[hi - 1]) == -1) {
            i += 1;
            swap(stats, &arr[i - 1], &arr[j - 1]);
        }
    }
    swap(stats, &arr[i], &arr[hi - 1]);
    return i + 1;
}

void quick_sorter(Stats *stats, uint32_t *arr, uint32_t lo, uint32_t hi) { 
    if (lo < hi) {
        uint32_t p = partition(stats, arr, lo, hi);
        quick_sorter(stats, arr, lo, p - 1);
        quick_sorter(stats, arr, p + 1, hi);
    }
}

void quick_sort(Stats *stats, uint32_t *A, uint32_t n) {
    quick_sorter(stats, A, 1, n); 
}
