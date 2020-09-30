#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void* custom_realloc(void *ptr, size_t size) {
    if (ptr == NULL) {
        return malloc(size);
    } else if (ptr == 0) {
        free(ptr);
        return NULL;
    } else if (size < sizeof(ptr)) {
        free(ptr + sizeof(ptr));
        return ptr;
    } else {
        void *_ptr = ptr + size;
        _ptr = (void *)malloc(size);
        return ptr;
    }
}

int main() {
	srand(time(NULL));

	printf("Enter original array size:");
	int n1 = 0;
	scanf("%d", &n1);

	int* a1 = (int*)malloc(sizeof(int) * n1);
	int i;
	for(i = 0; i < n1; i++){
		a1[i] = 100;
		printf("%d ", a1[i]);
	}

	printf("\nEnter new array size: ");
	int n2 = 0;
	scanf("%d", &n2);

	a1 = (int*)custom_realloc(a1, sizeof(int) * n2);

	for (int i = 0; i < n2; i++) {
		a1[i] = 0;
	}

	for(i = 0; i < n2; i++){
		printf("%d ", a1[i]);
	}
	printf("\n");
	
	return 0;
}
