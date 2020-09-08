#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char** argv) {
    int n;
    pid_t pid;

    sscanf(argv[1], "%d", &n);
    pid = fork();

    if (pid) {
        printf("Hello from parent [%d - %d]\n", pid, n);
    }
    else {
        printf("Hello from child [%d - %d]\n", pid, n);
    }
    return 0;
}

/*
Each child gets PID equals 0 as return value of fork(), while parent gets PID of a child.

Example of executing 10 times using ex1.sh script:

Hello from parent [10488 - 1]
Hello from child [0 - 1]
Hello from parent [10490 - 2]
Hello from child [0 - 2]
Hello from parent [10492 - 3]
Hello from child [0 - 3]
Hello from parent [10494 - 4]
Hello from child [0 - 4]
Hello from parent [10496 - 5]
Hello from child [0 - 5]
Hello from parent [10498 - 6]
Hello from child [0 - 6]
Hello from parent [10500 - 7]
Hello from child [0 - 7]
Hello from parent [10502 - 8]
Hello from child [0 - 8]
Hello from parent [10504 - 9]
Hello from child [0 - 9]
Hello from parent [10506 - 10]
Hello from child [0 - 10]
*/