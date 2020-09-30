#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    printf("Enter N: ");
    scanf("%d", &N);

    int* arr = (int*)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i += 1) {
        *(arr + i) = i;
    }

    for (int i = 0; i < N; i += 1) {
        printf("%d ", *(arr + i));
    }

    free(arr);

    return 0;
}