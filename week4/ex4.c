#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>

#define exit_command "exit"

int main() {
    char input[512];
    char* params[256];
    char* tmp;
    int status;

    while (1) {
        printf("$ ");
        
        fgets(input, 512, stdin);
        int length = strlen(input);
        if (input[length - 1] == '\n') {
            input[length - 1] = '\0';
        }

        int param_index = 0, value_index = 0;
        tmp = strtok(input, " ");
        while (tmp != NULL) {
            params[param_index++] = tmp;
            tmp = strtok(NULL, " ");
        }
        params[param_index] = NULL;
        
        char* cmd = params[0];
        if (strcmp(cmd, exit_command) == 0) {
            break;
        }

        if (fork() == 0) {
            exit(execvp(cmd, params));
        }
        wait(&status);
        if (WIFEXITED(status)) {
            printf("<%d>", WEXITSTATUS(status));
        }
        printf("\n");
    }

    return 0;
}