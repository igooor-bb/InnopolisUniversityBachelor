#include <stdio.h>
#include <stdlib.h>

#define CLOCK 1

struct Counter {
    int page_id;
    int value;
};

int main(int argc, char *argv[])
{
    int page_frames;

    if (argc < 2) {
        printf("Usage: %s page_frames\n", argv[0]);
    }
    else {
        sscanf(argv[1], "%d", &page_frames);
    }
    struct Counter *table = malloc(sizeof(struct Counter) * page_frames);
    int *ref = malloc(sizeof(page_frames));

    // Initialization
    for (int i = 0; i < page_frames; i += 1) {
        table[i].value = 0;
        table[i].page_id = -1;
    }

    FILE *input_file;
    input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error while open the input file\n");
        exit(1);
    }

    int page;
    int min = 0;
    int index = -1;

    int hit = 0;
    int miss = 0;
    int free = -1;
    while (!feof(input_file)) {
        for (int j = 0; j < page_frames; j += 1) {
            ref[j] = 0;
        }

        min = 0;
        index = -1;
        fscanf(input_file, "%d", &page);

        // Search for a matching value
        for (int i = 0; i < page_frames; i += 1) {
            if (table[i].page_id == page) index = i;
            if (table[i].value < table[min].value) min = i;
            if (table[i].page_id == -1) free = i;
        }

        // Search for a free space or a minimum value if a miss
        if (index < 0) {
            miss += 1;

            if (free > -1) {
                index = free;
                table[free].page_id = page;
                table[free].value = 0;
            } else {
                index = min;
                table[min].page_id = page;
                table[min].value = 0;
            }
        } else {
            hit += 1;
        }
        ref[index] = 1;
        
        for (int j = 0; j < page_frames; j += 1) {
            table[j].value = (ref[j] << 31) | (table[j].value >> 1);
        }

    }
    double res = (hit*1.0)/(miss);
    printf("hit/miss = %f\n", res);
    fclose(input_file);

    return 0;
}