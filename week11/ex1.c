#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>
#include <sys/stat.h>

int main() {
    const char* line = "This is a nice day";
    size_t line_size = strlen(line) + 1;

    int file = open("ex1.txt", O_RDWR | O_TRUNC, (mode_t)0600);

    ftruncate(file, line_size-1);

    char* map = mmap(0, line_size, PROT_READ | PROT_WRITE, MAP_SHARED, file, 0);
    memcpy(map, line, line_size - 1);
    msync(map, line_size, MS_ASYNC);
    munmap(map, line_size);

    close(file);
    return 0;
}