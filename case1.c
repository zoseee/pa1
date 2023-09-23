#include <stdio.h>

int addSum(int n) {
    int i;
    int total = 0;

    for (i = 0; i < n; i++) {
        total += i;
    }
    return total;
}

int main() {
    
    printf("Total : %d\n", addSum(10));

    return 0;
}