#include <stdio.h>
#include <time.h>

#define N 10000000000 // N = {100000000,1000000000,10000000000}

unsigned long long int addSum(unsigned long long int n) {
    unsigned long long int total = 0;

    total = ((N - 1ULL) * ((N - 1ULL) + 1ULL)) / 2ULL;  // Sum of an arithmetic series: Sum = (N/2) * (First term + last term)

    return total;
}

int main() {

    time_t start, end;

    time(&start);
    
    printf("Total : %llu\n", addSum(N));

    time(&end);

    double time_taken = ((double)(end - start));
    printf("Time taken: %0.5f sec\n", time_taken);

    return 0;
}