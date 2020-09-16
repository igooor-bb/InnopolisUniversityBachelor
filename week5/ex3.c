#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define BUFF_SIZE 100
#define LOOPS 100

int* buffer;

pthread_cond_t empty, full;
pthread_mutex_t mutex;

int fill_index = 0, use_index = 0, count = 0;

void* producer(void* arg) {
    for (int i = 0; i < LOOPS; i += 1) {
        pthread_mutex_lock(&mutex);
        while (count == BUFF_SIZE) {
            pthread_cond_wait(&empty, &mutex);
        }

        buffer[fill_index] = i;
        fill_index = (fill_index + 1) % BUFF_SIZE;
        count += 1;

        pthread_cond_signal(&full);
        pthread_mutex_unlock(&mutex);
    }

    return NULL;
}

void* consumer(void* arg) {
    for (int i = 0; i < LOOPS; i += 1) {
        pthread_mutex_lock(&mutex);
        
        while (count == 0) {
            pthread_cond_wait(&full, &mutex);
        }
        
        int value = buffer[use_index];
        use_index = (use_index + 1) % BUFF_SIZE;
        count -= 1;

        pthread_cond_signal(&empty);
        pthread_mutex_unlock(&mutex);

        printf("Consumed item %d\n", value);
    }

    return NULL;
}

int main() {
    pthread_t prod, cons;

    buffer = malloc(sizeof(int) * BUFF_SIZE);

    // Create producer
    pthread_create(&prod, NULL, producer, NULL);

    // Create consumer
    pthread_create(&cons, NULL, consumer, NULL);

    // Waiting for producer and consumer to finish
    pthread_join(prod, NULL);
    pthread_join(cons, NULL);
    

    return 0;
}