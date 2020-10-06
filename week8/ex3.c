#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    for (int i = 0; i < 10; i += 1) {
        int* p = (int*)malloc(10 * 1024 * 1024);
        memset(p, 0, 10 * 1024 * 1024);
        sleep(1);
    }

    return 0;
}

/*
top command also doesn't show any changes in swap
*/