#include <stdio.h>
#include <pthread.h>
#include <time.h>

#define NUM_THREADS 2
#define N 100000000


long long int partialSums[NUM_THREADS] = {0};

void* addSum(void* arg) {
    int thread_id = *(int*)arg;
    long long int chunk_size = N / NUM_THREADS;
    long long int start = thread_id * chunk_size;
    long long int end = (thread_id == NUM_THREADS - 1) ? N : start + chunk_size;
    long long int partial_sum = 0;

    for (long long int i = start; i < end; i++) {
        partial_sum += i;
    }

    partialSums[thread_id] = partial_sum;

    

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    long long int thread_ids[NUM_THREADS];

    struct timespec start_time, end_time;

    clock_gettime(CLOCK_MONOTONIC, &start_time);

    struct timespec start_time, end_time;
    clock_gettime(CLOCK_MONOTONIC, &start_time);

    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, addSum, &thread_ids[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    long long int total = 0;
    for (int i = 0; i < NUM_THREADS; i++) {
        total += partialSums[i];
    }

    clock_gettime(CLOCK_MONOTONIC, &end_time);

    double time_taken = (end_time.tv_sec - start_time.tv_sec) + (end_time.tv_nsec - start_time.tv_nsec) / 1e9;

    printf("Total : %lld\n", total);
    printf("Time taken for %d threads: %0.9f sec\n",NUM_THREADS, time_taken);



    return 0;
}
