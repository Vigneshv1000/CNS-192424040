#include <stdio.h>

int main() {
    int q = 23, a = 5;
    int x = 6, y = 15;
    int A = 1, B = 1;
    int key1 = 1, key2 = 1;

    for (int i = 0; i < x; i++)
        A = (A * a) % q;

    for (int i = 0; i < y; i++)
        B = (B * a) % q;

    for (int i = 0; i < x; i++)
        key1 = (key1 * B) % q;

    for (int i = 0; i < y; i++)
        key2 = (key2 * A) % q;

    printf("Alice Public Value: %d\n", A);
    printf("Bob Public Value: %d\n", B);
    printf("Alice Shared Key: %d\n", key1);
    printf("Bob Shared Key: %d\n", key2);

    return 0;
}
