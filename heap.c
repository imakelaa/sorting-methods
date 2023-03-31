#include "heap.h"

#include "gaps.h"
#include "stats.h"

#include <stdbool.h>
#include <stdio.h>

//HEAP SORT ALGORITHM

int max_child(Stats *stats, uint32_t *arr, int first, int last) {
    int left = 2 * first;
    int right = left + 1;
    if ((right <= last) && (cmp(stats, arr[right - 1], arr[left - 1]) == 1)) {
        return right;
    }
    return left;
}

void fix_heap(Stats *stats, uint32_t *arr, int first, int last) {
    bool found = false;
    int mother = first;
    int great = max_child(stats, arr, mother, last);

    while ((mother <= (last / 2)) && !found) {
        if (cmp(stats, arr[mother - 1], arr[great - 1]) == -1) {
            swap(stats, &arr[mother - 1], &arr[great - 1]);
            mother = great;
            great = max_child(stats, arr, mother, last);
        } else {
            found = true;
        }
    }
}

void build_heap(Stats *stats, uint32_t *arr, int first, int last) {
    int father;
    for (father = (last / 2); father > (first - 1); father -= 1) {
        fix_heap(stats, arr, father, last);
    }
}

void heap_sort(Stats *stats, uint32_t *arr, uint32_t n) {
    int first = 1;
    int last = n;
    build_heap(stats, arr, first, last);
    int leaf;
    for (leaf = last; leaf > first; leaf -= 1) {
        swap(stats, &arr[first - 1], &arr[leaf - 1]);
        fix_heap(stats, arr, first, leaf - 1);
    }
}
