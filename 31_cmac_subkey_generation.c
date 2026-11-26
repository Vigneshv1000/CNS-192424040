#include <stdio.h>
#include <stdint.h>

int main() {
    uint64_t L = 0x123456789ABCDEF0ULL;
    uint64_t K1, K2;

    K1 = L << 1;
    if (L >> 63)
        K1 ^= 0x1B;

    K2 = K1 << 1;
    if (K1 >> 63)
        K2 ^= 0x1B;

    printf("First Subkey: %016llX\n", (unsigned long long)K1);
    printf("Second Subkey: %016llX\n", (unsigned long long)K2);
    printf("64-bit reduction constant: 0x1B\n");
    printf("128-bit reduction constant: 0x87\n");

    return 0;
}
