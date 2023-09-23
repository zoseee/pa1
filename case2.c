#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 8
#define N 100000000

int partialSums[NUM_THREADS] = {0};

void* addSum(void* arg) {
    int thread_id = *(int*)arg;
    int chunk_size = N / NUM_THREADS;
    int start = thread_id * chunk_size;
    int end = (thread_id == NUM_THREADS - 1) ? N : start + chunk_size;
    int partial_sum = 0;

    for (int i = start; i < end; i++) {
        partial_sum += i;
    }

    partialSums[thread_id] = partial_sum;

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, addSum, &thread_ids[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    int total = 0;
    for (int i = 0; i < NUM_THREADS; i++) {
        total += partialSums[i];
    }

    printf("Total : %d\n", total);

    return 0;
}
