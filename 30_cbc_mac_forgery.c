#include <stdio.h>

int main() {
    int X = 10;
    int T = 7;
    int second = X ^ T;

    printf("Original Message: %d\n", X);
    printf("MAC of X: %d\n", T);
    printf("Second Block: %d\n", second);
    printf("Forged two-block message: %d || %d\n", X, second);
    printf("Forged MAC: %d\n", T);

    return 0;
}
