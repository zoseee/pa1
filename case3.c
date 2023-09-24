#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define NUM_TASKS 4
#define N 100000000

int main() {
    int total = 0;
    int pipefd[NUM_TASKS][2]; // Array of pipes for communication

    // Create pipes for communication between parent and child processes
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

        if (pid == 0) { // Child process
            int start = task * (N / NUM_TASKS);
            int end = (task == NUM_TASKS - 1) ? N : (task + 1) * (N / NUM_TASKS);
            int partial_sum = 0;

            // Calculate the partial sum for this task
            for (int i = start; i < end; i++) {
                partial_sum += i;
            }

            // Write the partial sum to the pipe
            write(pipefd[task][1], &partial_sum, sizeof(int));

            // Close the write end of the pipe
            close(pipefd[task][1]);

            exit(EXIT_SUCCESS);
        }
    }

    // Parent process
    for (int i = 0; i < NUM_TASKS; i++) {
        int status;
        wait(&status);

        // Read the partial sum from the pipe
        int partial_sum;
        read(pipefd[i][0], &partial_sum, sizeof(int));

        // Close the read end of the pipe
        close(pipefd[i][0]);

        // Accumulate the partial sum
        total += partial_sum;
    }

    printf("Total : %d\n", total);

    return 0;
}
