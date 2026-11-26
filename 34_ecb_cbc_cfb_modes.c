#include <stdio.h>

int main() {
    int p[4] = {10, 20, 30, 40};
    int key = 5, iv = 7;
    int ecb[4], cbc[4], cfb[4];
    int prev = iv;

    printf("ECB: ");
    for (int i = 0; i < 4; i++) {
        ecb[i] = p[i] ^ key;
        printf("%d ", ecb[i]);
    }

    printf("\nCBC: ");
    for (int i = 0; i < 4; i++) {
        cbc[i] = (p[i] ^ prev) ^ key;
        prev = cbc[i];
        printf("%d ", cbc[i]);
    }

    printf("\nCFB: ");
    prev = iv;
    for (int i = 0; i < 4; i++) {
        cfb[i] = p[i] ^ (prev ^ key);
        prev = cfb[i];
        printf("%d ", cfb[i]);
    }

    printf("\n");
    return 0;
}
