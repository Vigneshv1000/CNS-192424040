#include <stdio.h>

int main() {
    int e = 3, n = 55;
    int msg[] = {7, 4, 11, 11, 14};
    int i, j, c;

    printf("Encrypted Message: ");
    for (i = 0; i < 5; i++) {
        c = 1;
        for (j = 0; j < e; j++)
            c = (c * msg[i]) % n;
        printf("%d ", c);
    }

    return 0;
}
