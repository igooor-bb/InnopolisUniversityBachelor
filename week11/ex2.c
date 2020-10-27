#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main() {
    const char* line = "Hello";
    setvbuf(stdout, NULL, _IOFBF, strlen(line));
    for (int i = 0; i < strlen(line); i += 1) {
        printf("%c", line[i]);
        sleep(1);
    }
    return 0;
}