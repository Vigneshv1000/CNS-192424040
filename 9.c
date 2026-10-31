#include <stdio.h>
#include <string.h>

char matrix[5][5] = {
    {'M','O','N','A','R'},
    {'C','H','Y','B','D'},
    {'E','F','G','I','K'},
    {'L','P','Q','S','T'},
    {'U','V','W','X','Z'}
};

void findPosition(char c, int *r, int *col)
{
    int i, j;

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
    char text[] =
    "KXJEYUREBEZWEHEWRYTUHEYFSKREHEGOYFIWTTTUOLKSYCAJPO"
    "BOTEIZONTXBYBNTGONEYCUZWRGDSONSXBOUYWRHEBAAHYUSEDQ";

    int i, r1, c1, r2, c2;

    for(i = 0; text[i] != '\0'; i += 2)
    {
        findPosition(text[i], &r1, &c1);
        findPosition(text[i+1], &r2, &c2);

        if(r1 == r2)
        {
            text[i] = matrix[r1][(c1 + 4) % 5];
            text[i+1] = matrix[r2][(c2 + 4) % 5];
        }
        else if(c1 == c2)
        {
            text[i] = matrix[(r1 + 4) % 5][c1];
            text[i+1] = matrix[(r2 + 4) % 5][c2];
        }
        else
        {
            text[i] = matrix[r1][c2];
            text[i+1] = matrix[r2][c1];
        }
    }

    printf("Decrypted message:\n%s\n", text);

    return 0;
}