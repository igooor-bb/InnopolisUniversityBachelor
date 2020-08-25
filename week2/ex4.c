#include <stdio.h>

void swap(int* first, int* second) {
    int tmp = *first; 
    *first = *second; 
    *second = tmp;
}

int main() {
    int first, second;
    printf("First number: ");
    scanf("%d", &first);
    printf("Second number: ");
    scanf("%d", &second);

    printf("First: %d\n", first);
    printf("Second: %d\n", second);

    printf("Swap\n");
    swap(&first, &second);
    
    printf("First: %d\n", first);
    printf("Second: %d\n", second);

    return 0;
}