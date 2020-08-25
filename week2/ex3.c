#include <stdio.h>

int main(int argc, char* argv[]) {
    int n;
    if (argc < 2) {
        printf("Usage: program_name number_of_items\n");
    } else {
        sscanf(argv[1], "%d", &n);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++)
                putc(' ', stdout);
            for (int j = 0; j < 2 * i + 1; j++)
                putc('*', stdout);
            putc('\n', stdout);
        }
    }
    return 0;
}