#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

#define NUM_TASKS 4
<<<<<<< HEAD
#define N 1000000000

int main() {
    long long int total = 0;
    int pipefd[NUM_TASKS][2]; //pipesssssssssssssssssssssssssssssssssssssssss
=======
<<<<<<< HEAD
#define N 10000000000
=======
#define N 100000000
>>>>>>> 0751a3b2a41ce00e32cbe652de21c30d18631891

int main() {
    long long int total = 0;
    int pipefd[NUM_TASKS][2]; // Array of pipes for communication
>>>>>>> 0a8ecfce85f7a731adbef61eb4fc84075915da85

    struct timespec start_time, end_time;

    clock_gettime(CLOCK_MONOTONIC, &start_time);

    //pipes for parent and child
    for (int i = 0; i < NUM_TASKS; i++) {
        if (pipe(pipefd[i]) == -1) {
            perror("pipe");
            exit(EXIT_FAILURE);
        }
    }

    for (int task = 0; task < NUM_TASKS; task++) {
        pid_t pid = fork();

        if (pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        }

<<<<<<< HEAD
        if (pid == 0) { //child
            long long int start = task * (N / NUM_TASKS);
            long long int end = (task == NUM_TASKS - 1) ? N : (task + 1) * (N / NUM_TASKS);
=======
        if (pid == 0) { // Child process
            int start = task * (N / NUM_TASKS);
            int end = (task == NUM_TASKS - 1) ? N : (task + 1) * (N / NUM_TASKS);
>>>>>>> 0a8ecfce85f7a731adbef61eb4fc84075915da85
            long long int partial_sum = 0;

            //calc partial sum
            for (int i = start; i < end; i++) {
                partial_sum += i;
            }

<<<<<<< HEAD
            //write sum to pipe
=======
            // Write the partial sum to the pipe
>>>>>>> 0a8ecfce85f7a731adbef61eb4fc84075915da85
            write(pipefd[task][1], &partial_sum, sizeof(long long int));

            //close write
            close(pipefd[task][1]);

            exit(EXIT_SUCCESS);
        }
    }

    //parent
    for (int i = 0; i < NUM_TASKS; i++) {
        int status;
        wait(&status);

<<<<<<< HEAD
        //read sum from pipe
=======
        // Read the partial sum from the pipe
>>>>>>> 0a8ecfce85f7a731adbef61eb4fc84075915da85
        long long int partial_sum;
        read(pipefd[i][0], &partial_sum, sizeof(long long int));

        //close read
        close(pipefd[i][0]);

        //add up partial sum
        total += partial_sum;
    }

<<<<<<< HEAD
    double time_taken = (end_time.tv_sec - start_time.tv_sec) + (end_time.tv_nsec - start_time.tv_nsec) / 1e9;

=======
>>>>>>> 0a8ecfce85f7a731adbef61eb4fc84075915da85
    printf("Total : %lld\n", total);

    return 0;
}
