#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

#define LETTERS_NUMBER 20

int main() {
    int random_data = open("/dev/random", O_RDONLY);

    char result_string[LETTERS_NUMBER];
    size_t index = 0;

    while (index <= LETTERS_NUMBER) {
        ssize_t ret = read(random_data, result_string + index, 1);
        if (isalpha(result_string[index]) || isdigit(result_string[index])) {
            index += ret;
        }
    }

    close(random_data);
    printf("%s", result_string);

    return 0;
}

