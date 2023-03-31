#include "batcher.h"
#include "gaps.h"
#include "heap.h"
#include "quick.h"
#include "set.h"
#include "shell.h"
#include "stats.h"

#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define sort_shell   0
#define sort_heap    1
#define sort_quick   2
#define sort_batcher 3
#define OPTIONS      "ahbsqr:n:p:H"

void usage(char *exec) {
    fprintf(stderr,
        "SYNOPSIS\n   collection of comparison-based sorting algorithms.\n\nUSAGE\n   %s "
        "[-Hasbhqn:p:r:] [-n length] [-p elements] [-r seed]\n\nOPTIONS\n   -H              "
        "Display program help and usage.\n   -a              Enable all sorts.\n   -s              "
        "Enable Shell Sort.\n   -b              Enable Batcher Sort.\n   -h              Enable "
        "Heap Sort.\n   -q              Enable Quick Sort.\n   -n length       Specify number of "
        "array elements (default: 100).\n   -p elements     Specify number of elements to print "
        "(default: 100).\n   -r seed         Specify random seed (default: 13371453).\n",
        exec);
} 

int main(int argc, char **argv) {
    int opt = 0;
    Set set = set_empty();

    
    uint32_t seed = 13371453;
    uint32_t size = 100; 
    uint32_t elements = 100;
    uint32_t *arr1 = NULL;

    Stats stats;

    
    while ((opt = getopt(argc, argv, OPTIONS)) != -1) {
        switch (opt) {
        case 'a': set = set_universal(); break;
        case 'h': set = set_insert(set, 1); break; //where to add sizeof()?
        case 'b': set = set_insert(set, 3); break;
        case 's': set = set_insert(set, 0); break;
        case 'q': set = set_insert(set, 2); break;
        case 'r': seed = strtoul(optarg, NULL, 10); break;
        case 'n': size = strtoul(optarg, NULL, 10); break;
        case 'p': elements = strtoul(optarg, NULL, 10); break;
        case 'H':
            printf("SYNOPSIS\n   collection of comparison-based sorting algorithms.\n\nUSAGE\n   "
                   "/.sorting [-Hasbhqn:p:r:] [-n length] [-p elements] [-r seed]\n\nOPTIONS\n   "
                   "-H              Display program help and usage.\n   -a              Enable all "
                   "sorts.\n   -s              Enable Shell Sort.\n   -b              Enable "
                   "Batcher Sort.\n   -h              Enable Heap Sort.\n   -q              Enable "
                   "Quick Sort.\n   -n length       Specify number of array elements (default: "
                   "100).\n   -p elements     Specify number of elements to print (default: "
                   "100).\n   -r seed         Specify random seed (default: 13371453).\n");
            break;
        }
    }

    if (argc < 2) {
        printf("Select at least one of these cases to perform.\n");
        usage(argv[0]);
    }

    arr1 = (uint32_t *) calloc(size, sizeof(uint32_t));

    if (elements > size) {
        elements = size;
    }
    srandom(seed);
    for (uint32_t i = 0; i < size; i += 1) {
        arr1[i] = random() & ((1 << 30) - 1);
    }

    
    reset(&stats);

    if (set_member(set, 3)) {
        batcher_sort(&stats, arr1, size);
        printf("Batcher Sort, %u elements, %lu moves, %lu compares\n", size, stats.moves,
            stats.compares);
        for (uint32_t i = 0; i < elements; i++) {
            printf("%13" PRIu32, arr1[i]);
            if (((i + 1) % 5) == 0) {
                printf("\n");
            }
        }
    }

    if (elements > size) {
        elements = size;
    }

    srandom(seed);

    for (uint32_t i = 0; i < size; i += 1) {
        arr1[i] = random() & ((1 << 30) - 1);
    }

    reset(&stats);

    if (set_member(set, 0)) {
        shell_sort(&stats, arr1, size);
        printf("Shell Sort, %u elements, %lu moves, %lu compares\n", size, stats.moves,
            stats.compares);
        for (uint32_t i = 0; i < elements; i++) {
            printf("%13" PRIu32, arr1[i]);
            if (((i + 1) % 5) == 0) {
                printf("\n");
            }
        }
    }

    if (elements > size) {
        elements = size;
    }

    
    srandom(seed);

    for (uint32_t i = 0; i < size; i += 1) {
        arr1[i] = random() & ((1 << 30) - 1);
    }

    reset(&stats);

    if (set_member(set, 1)) {
        heap_sort(&stats, arr1, size);
        printf(
            "Heap Sort, %u elements, %lu moves, %lu compares\n", size, stats.moves, stats.compares);
        for (uint32_t i = 0; i < elements; i++) {
            printf("%13" PRIu32, arr1[i]);
            if (((i + 1) % 5) == 0) {
                printf("\n");
            }
        }
    }

    if (elements > size) {
        elements = size;
    }

    srandom(seed);

    for (uint32_t i = 0; i < size; i += 1) {
        arr1[i] = random() & ((1 << 30) - 1);
    }

    reset(&stats);

    if (set_member(set, 2)) {
        quick_sort(&stats, arr1, size);
        printf("Quick Sort, %u elements, %lu moves, %lu compares\n", size, stats.moves,
            stats.compares);
        for (uint32_t i = 0; i < elements; i++) {
            printf("%13" PRIu32, arr1[i]);
            if (((i + 1) % 5) == 0) {
                printf("\n");
            }
        }
    }

    reset(&stats);

    free(arr1);
    return 0;
}
