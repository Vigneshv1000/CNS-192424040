#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char text[200], cipher[200], plain[200];
    int key[2][2] = {{9,4},{5,7}};
    int inv[2][2] = {{7,22},{21,9}};
    int i, a, b, x, y, len;

    printf("Enter plaintext: ");
    fgets(text, sizeof(text), stdin);

    len = 0;

    for(i = 0; text[i] != '\0'; i++)
        if(isalpha(text[i]))
            text[len++] = tolower(text[i]);

    text[len] = '\0';

    if(len % 2 != 0)
        text[len++] = 'x';

    for(i = 0; i < len; i += 2)
    {
        a = text[i] - 'a';
        b = text[i+1] - 'a';

        x = (key[0][0]*a + key[0][1]*b) % 26;
        y = (key[1][0]*a + key[1][1]*b) % 26;

        cipher[i] = x + 'a';
        cipher[i+1] = y + 'a';
    }

    cipher[len] = '\0';

    printf("\nEncrypted text: %s\n", cipher);

    for(i = 0; i < len; i += 2)
    {
        a = cipher[i] - 'a';
        b = cipher[i+1] - 'a';

        x = (inv[0][0]*a + inv[0][1]*b) % 26;
        y = (inv[1][0]*a + inv[1][1]*b) % 26;

        plain[i] = x + 'a';
        plain[i+1] = y + 'a';
    }

    plain[len] = '\0';

    printf("Decrypted text: %s\n", plain);

    return 0;
}