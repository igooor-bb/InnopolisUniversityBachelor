#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/resource.h>

int main() {
    struct rusage usage;

    for (int i = 0; i < 10; i += 1) {
        int* p = (int*)malloc(10 * 1024 * 1024);
        memset(p, 0, 10 * 1024 * 1024);
        int ret = getrusage(RUSAGE_SELF, &usage);
        printf("%ld\n", usage.ru_maxrss);
        sleep(1);
    }

    return 0;
}