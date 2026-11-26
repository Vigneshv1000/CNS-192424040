#include <stdio.h>

int main() {
    int message = 10;
    int privateKey = 7;
    int k1 = 3, k2 = 5;

    int signature1 = (message + privateKey * k1) % 23;
    int signature2 = (message + privateKey * k2) % 23;

    printf("Message: %d\n", message);
    printf("First Signature: %d\n", signature1);
    printf("Second Signature: %d\n", signature2);

    if (signature1 != signature2)
        printf("Signatures are Different\n");
    else
        printf("Signatures are Same\n");

    return 0;
}
