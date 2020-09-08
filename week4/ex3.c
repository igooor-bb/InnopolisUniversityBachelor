#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int state = 1;
    char cmd[256];

    while(state) { 
        printf("$ ");
        fgets(cmd, 256, stdin);
        if(cmd[strlen(cmd) - 1] == '\n') {
            cmd[strlen(cmd) - 1] = 0;
        }
    
        if (strcmp(cmd, "exit") == 0) {
            state = 0;
        } else {
            system(cmd);
        }
    }
    return 0;
}