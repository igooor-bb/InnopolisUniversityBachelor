#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

int main() {
    FILE* input_file = fopen("input_dl.txt", "r");

    int resources_number, processes_number;
    fscanf(input_file, "%d %d", &resources_number, &processes_number);

    int existing[resources_number];
    int allocated[resources_number];

    int C[processes_number][resources_number];
    int R[processes_number][resources_number];

    for (int i = 0; i < resources_number; i += 1) {
        fscanf(input_file, "%d", &existing[i]);
    }

    for (int i = 0; i < resources_number; i += 1) {
        fscanf(input_file, "%d", &allocated[i]);
    }

    for (int i = 0; i < processes_number; i += 1) {
        for (int j = 0; j < resources_number; j += 1) {
            fscanf(input_file, "%d", &C[i][j]);
        }
    }

    for (int i = 0; i < processes_number; i += 1) {
        for (int j = 0; j < resources_number; j += 1) {
            fscanf(input_file, "%d", &R[i][j]);
        }
    }
    
    fclose(input_file);

    int checked[processes_number];
    for (int i = 0; i < processes_number; i += 1) {
        checked[i] = FALSE;
    }
    while (TRUE) {
        int valid = FALSE;
        for (int i = 0; i < processes_number; i += 1) {
            if (!checked[i]) {
                int found = FALSE;
                for (int j = 0; j < resources_number; j += 1) {
                    if (R[i][j] > allocated[j]) {
                        found = TRUE;
                        break;
                    }
                }

                if (!found) {
                    for (int j = 0; j < resources_number; j += 1) {
                        allocated[j] += C[i][j];
                    }
                    checked[i] = TRUE;
                    valid = TRUE;
                }
            }
        }
        if (!valid) {
            break;
        }
    }

    FILE* output_file = fopen("output_dl.txt", "w");
    int deadlocks_number = 0;
    for (int i = 0; i < processes_number; i += 1) {
        if (!checked[i]) {
            fprintf(output_file, "%d ", i + 1);
            deadlocks_number += 1;
        }
    }

    if (deadlocks_number == 0) {
        fprintf(output_file, "No deadlocks\n");
    }

    fclose(output_file);
    return 0;
}