#include <stdio.h>
#include <string.h>

#define STRING_LIMIT 512

int main() {
    char str[STRING_LIMIT];
    char result[STRING_LIMIT];
    int i;

    fgets(str, STRING_LIMIT, stdin);

    for (i = strlen(str) - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }

    printf("\n");

    return 0;
}


