#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <ctype.h>
#include <string.h>

#define BUFFER_SIZE 128000

int main(int argc, char* argv[]) {
    char buffer[BUFFER_SIZE];
    fread(buffer, sizeof(char), BUFFER_SIZE, stdin);

    int append_mode = 0;

    char token;
    while ((token = getopt(argc, argv, "a")) != -1) {
        if (token == 'a') {
            append_mode = 1;
        } else if (token == '?') {
            exit(0);
        }
	}

    char* file_mode = append_mode ? "a" : "w";
    int files_number = argc - optind;

    
    if (files_number > 0) {
        for (int i = optind; i < argc; i += 1) {
            FILE* fd = fopen(argv[i], file_mode);
            fwrite(buffer, sizeof(char), strlen(buffer), fd);
            fclose(fd);
        }
    }

    return 0;
}