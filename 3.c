#include <stdio.h>
#include <string.h>
#include <ctype.h>

char matrix[5][5];
char key[] = "MONARCHY";

void generateMatrix()
{
    int used[26] = {0};
    int i, j, k = 0;
    char c;

    used['J' - 'A'] = 1;

    for(i = 0; key[i] != '\0'; i++)
    {
        c = toupper(key[i]);

        if(c == 'J')
            c = 'I';

        if(!used[c - 'A'])
        {
            matrix[k / 5][k % 5] = c;
            used[c - 'A'] = 1;
            k++;
        }
    }

    for(c = 'A'; c <= 'Z'; c++)
    {
        if(!used[c - 'A'])
        {
            matrix[k / 5][k % 5] = c;
            k++;
        }
    }
}

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
    char text[100], result[200], a, b;
    int i, r1, c1, r2, c2, k = 0;

    generateMatrix();

    printf("Enter plaintext: ");
    fgets(text, sizeof(text), stdin);

    for(i = 0; text[i] != '\0'; i++)
        if(isalpha(text[i]))
            text[k++] = toupper(text[i]);

    text[k] = '\0';

    k = 0;

    for(i = 0; text[i] != '\0'; i += 2)
    {
        a = text[i];
        b = text[i + 1];

        if(b == '\0')
            b = 'X';

        if(a == b)
        {
            b = 'X';
            i--;
        }

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

    printf("Encrypted text: %s\n", result);

    return 0;
}