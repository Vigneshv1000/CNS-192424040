#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char text[100];
    char key[] = "CIPHER";
    char cipher[26];
    int used[26] = {0};
    int i, j = 0;

    for(i = 0; key[i] != '\0'; i++)
    {
        char c = toupper(key[i]);

        if(!used[c - 'A'])
        {
            cipher[j++] = c;
            used[c - 'A'] = 1;
        }
    }

    for(i = 0; i < 26; i++)
    {
        if(!used[i])
            cipher[j++] = 'A' + i;
    }

    printf("Enter plaintext: ");
    getchar();
    fgets(text, sizeof(text), stdin);

    for(i = 0; text[i] != '\0'; i++)
    {
        if(isupper(text[i]))
            text[i] = cipher[text[i] - 'A'];

        else if(islower(text[i]))
            text[i] = tolower(cipher[text[i] - 'a']);
    }

    printf("Encrypted text: %s", text);

    return 0;
}