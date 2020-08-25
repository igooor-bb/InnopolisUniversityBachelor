#include <stdio.h>

void display_type1(int n) {
    // The first type of figure
    for (int i = 0; i < n; i += 1) {
        for (int j = 0; j <= i; j += 1) {
            putc('*', stdout);
        }
        putc('\n', stdout);
    }
}

void display_type2(int n) {
    // The second type of figure
    for (int i = 0; i < n; i += 1) {
        for (int j = 0; j <= i; j += 1)
            putc('*', stdout);
        putc('\n', stdout);
    }
    for (int i = 1; i < n; i += 1) {
        for (int j = i; j < n; j += 1) {
            putc('*', stdout);
        }
        putc('\n', stdout);
    }
}

void display_type3(int n) {
    // The third type of figure
    for (int i = 0; i < n; i += 1) {
        for (int j = 0; j < n; j += 1) {
            putc('*', stdout);
        }
        putc('\n', stdout);
    }
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: program_name number_of_items type_of_figure{1-3}\n");
    } else {
        int n;
        sscanf(argv[1], "%d", &n);
        int type;
        sscanf(argv[2], "%d", &type);
        if (type == 1) {
            display_type1(n);
        } else if (type == 2) {
            display_type2(n);
        } else if (type == 3) {
            display_type3(n);
        } else {
            printf("Usage: program_name number_of_items type_of_figure{1-3}\n");
        }
    }
    return 0;
}