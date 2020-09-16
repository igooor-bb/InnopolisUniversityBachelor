#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>
#include <pthread.h>

#define THREADS_NUMBER 5

pthread_mutex_t lock;

void* thread_function(void* thread_id) {
    int* id = (int*)thread_id;
    printf("[Thread ID%d] Hello\n", *id);

    return NULL;
}

int main() {
    pthread_t threads[THREADS_NUMBER]; 

    int i;
    for(i = 0; i < THREADS_NUMBER; i += 1) {
        pthread_create(&threads[i], NULL, thread_function, (void*)&i);
        printf("[Main] Creating thread %d\n", i);
        pthread_join(threads[i], NULL);
    }

    return 0;
}