#include <stdio.h>

int main() {
    int state = 1600;
    int block = 1024;
    int capacity = state - block;
    int lanes = capacity / 64;

    printf("Total State Size: %d bits\n", state);
    printf("Block Size: %d bits\n", block);
    printf("Capacity: %d bits\n", capacity);
    printf("Zero Lanes: %d\n", lanes);
    printf("Time to become nonzero: Never (permutation ignored)\n");

    return 0;
}
