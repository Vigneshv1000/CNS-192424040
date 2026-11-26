#include <stdio.h>

int main() {
    int p = 3, q = 11;
    int n = p * q;
    int e = 3, d = 7;
    int msg = 4, encrypted = 1, decrypted = 1;

    for (int i = 0; i < e; i++)
        encrypted = (encrypted * msg) % n;

    for (int i = 0; i < d; i++)
        decrypted = (decrypted * encrypted) % n;

    printf("Public Key: (%d, %d)\n", e, n);
    printf("Private Key: (%d, %d)\n", d, n);
    printf("Original Message: %d\n", msg);
    printf("Encrypted Message: %d\n", encrypted);
    printf("Decrypted Message: %d\n", decrypted);

    return 0;
}
