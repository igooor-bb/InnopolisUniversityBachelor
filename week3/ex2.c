#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int arr[], int N) {
    for (int i = 0; i < N-1; i++) {
        for (int j = 0; j < N-i; j++) {
            if (arr[j] > arr[j+1]) {
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}

int main() {
    int N;
    printf("Enter number of elements: ");
    scanf("%d\n", &N);

    int* arr = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i += 1) {
        scanf("%d", &arr[i]);
    }
    bubble_sort(arr, N); 
    
    for (int i = 0; i < N; i += 1) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}