#include "shell.h"

#include "gaps.h"
#include "stats.h"

#include <stdio.h>

//SHELL SORT

void shell_sort(Stats *stats, uint32_t *arr, uint32_t length) {
    for (uint32_t gap = 0; gap < GAPS; gap++) {
        uint32_t gap1 = gaps[gap];
        for (uint32_t i = gap1; i < length; i++) {
            uint32_t j = i;
            uint32_t temp = move(stats, arr[i]);
            while ((j >= gap1) && cmp(stats, temp, arr[j - gap1]) == -1) {
                arr[j] = move(stats, arr[j - gap1]);
                j -= gap1;
            }
            arr[j] = move(stats, temp);
        }
    }
}
