#include <stdio.h>

int main()
{
    int p[2][2], c[2][2];
    int inv[2][2];
    int det, inverse = -1;
    int key[2][2];

    printf("Enter plaintext matrix:\n");

    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            scanf("%d", &p[i][j]);

    printf("Enter ciphertext matrix:\n");

    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            scanf("%d", &c[i][j]);

    det = (p[0][0]*p[1][1] -
           p[0][1]*p[1][0]) % 26;

    if(det < 0)
        det += 26;

    for(int i = 1; i < 26; i++)
        if((det*i)%26 == 1)
            inverse = i;

    if(inverse == -1)
    {
        printf("Plaintext matrix has no inverse modulo 26\n");
        return 0;
    }

    inv[0][0] = p[1][1];
    inv[0][1] = -p[0][1];
    inv[1][0] = -p[1][0];
    inv[1][1] = p[0][0];

    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
        {
            inv[i][j] = (inv[i][j]*inverse)%26;

            if(inv[i][j] < 0)
                inv[i][j] += 26;
        }

    printf("Recovered Key Matrix:\n");

    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            key[i][j] = 0;

            for(int k = 0; k < 2; k++)
                key[i][j] += c[i][k]*inv[k][j];

            key[i][j] %= 26;

            printf("%d ", key[i][j]);
        }

        printf("\n");
    }

    return 0;
}