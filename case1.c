#include <stdio.h>
#include <time.h>

<<<<<<< HEAD
#define N 100000000 // N = {100000000,1000000000,10000000000}
=======
#define N 10000000000 // N = {100000000,1000000000,10000000000}
>>>>>>> 0a8ecfce85f7a731adbef61eb4fc84075915da85

unsigned long long int addSum(unsigned long long int n) {
    unsigned long long int total = 0;

    total = ((N - 1ULL) * ((N - 1ULL) + 1ULL)) / 2ULL;  // Sum of an arithmetic series: Sum = (N/2) * (First term + last term)

    return total;
}

int main() {

    time_t start, end;

    time(&start);
    
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 0a8ecfce85f7a731adbef61eb4fc84075915da85
    printf("Total : %llu\n", addSum(N));

    time(&end);

    double time_taken = ((double)(end - start));
    printf("Time taken: %0.5f sec\n", time_taken);
<<<<<<< HEAD
=======
=======
    printf("Total : %d\n", addSum(100000000));
>>>>>>> 0751a3b2a41ce00e32cbe652de21c30d18631891
>>>>>>> 0a8ecfce85f7a731adbef61eb4fc84075915da85

    return 0;
}