#include <stdio.h>

int main() {
    int p[2][2], c[2][2];
    int det, inv = -1;
    int result[2][2];

    printf("Enter plaintext matrix:\n");
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            scanf("%d", &p[i][j]);

    printf("Enter ciphertext matrix:\n");
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            scanf("%d", &c[i][j]);

    det = (p[0][0] * p[1][1] - p[0][1] * p[1][0]) % 26;
    if (det < 0) det += 26;

    for (int i = 0; i < 26; i++)
        if ((det * i) % 26 == 1)
            inv = i;

    if (inv == -1) {
        printf("Key cannot be recovered: plaintext matrix has no inverse.\n");
        return 0;
    }

    int adj[2][2] = {
        {p[1][1], -p[0][1]},
        {-p[1][0], p[0][0]}
    };
    int inverse[2][2];

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++) {
            inverse[i][j] = (adj[i][j] * inv) % 26;
            if (inverse[i][j] < 0)
                inverse[i][j] += 26;
        }

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < 2; k++)
                result[i][j] += c[i][k] * inverse[k][j];
            result[i][j] %= 26;
        }

    printf("Recovered Key Matrix:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++)
            printf("%d ", result[i][j]);
        printf("\n");
    }

    return 0;
}
