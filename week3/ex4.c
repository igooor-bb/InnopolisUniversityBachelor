#include <stdio.h>
#include <stdlib.h>

void quicksort(int arr[], int left, int right) {
    int i, j, pivot, tmp;

    if (left < right) {
        pivot = left;
        i = left;
        j = right;
        
        while (i < j) {
            while(arr[i] <= arr[pivot] && i < right) i += 1;
            while(arr[j] > arr[pivot]) j -= 1;
            if (i < j) {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }

        tmp = arr[pivot];
        arr[pivot] = arr[j];
        arr[j] = tmp;
        quicksort(arr, left, j - 1);
        quicksort(arr, j + 1, right);
    }
}

int main() {
    int N;
    printf("Enter number of elements: ");
    scanf("%d", &N);

    int* arr = (int*)malloc(N * sizeof(int));
   
    for (int i = 0; i < N; i += 1) {
        scanf("%d", &arr[i]);
    }
    printf("Initial array: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    quicksort(arr, 0, N-1);
    printf("\nSorted array: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}