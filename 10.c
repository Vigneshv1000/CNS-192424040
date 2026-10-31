#include <stdio.h>
#include <string.h>
#include <ctype.h>

char matrix[5][5] = {
    {'M','F','H','I','K'},
    {'U','N','O','P','Q'},
    {'Z','V','W','X','Y'},
    {'E','L','A','R','G'},
    {'D','S','T','B','C'}
};

void findPosition(char c, int *r, int *col)
{
    int i, j;

    if(c == 'J')
        c = 'I';

    for(i = 0; i < 5; i++)
        for(j = 0; j < 5; j++)
            if(matrix[i][j] == c)
            {
                *r = i;
                *col = j;
            }
}

int main()
{
    char text[] = "MUSTSEEYOUOVERCADOGANWESTCOMINGATONCE";
    char result[100];
    int i, k = 0, r1, c1, r2, c2;

    for(i = 0; text[i] != '\0'; i += 2)
    {
        char a = text[i];
        char b = text[i+1];

        if(b == '\0')
            b = 'X';

        findPosition(a, &r1, &c1);
        findPosition(b, &r2, &c2);

        if(r1 == r2)
        {
            result[k++] = matrix[r1][(c1 + 1) % 5];
            result[k++] = matrix[r2][(c2 + 1) % 5];
        }
        else if(c1 == c2)
        {
            result[k++] = matrix[(r1 + 1) % 5][c1];
            result[k++] = matrix[(r2 + 1) % 5][c2];
        }
        else
        {
            result[k++] = matrix[r1][c2];
            result[k++] = matrix[r2][c1];
        }
    }

    result[k] = '\0';

    printf("Encrypted message: %s\n", result);

    return 0;
}