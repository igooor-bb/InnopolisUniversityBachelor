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
SI:      SO:
3114982  3462341
0        0
0        0
0        0
0        0
0        0
0        0
0        0
0        0
0        0

Since swap is not using, I have enough RAM (or MacOS knows better than me)
*/