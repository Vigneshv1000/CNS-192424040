#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char text[100];
    char key[] = "QWERTYUIOPASDFGHJKLZXCVBNM";
    int i;

    printf("Enter plaintext: ");
    fgets(text, sizeof(text), stdin);

    for(i = 0; text[i] != '\0'; i++)
    {
        if(isupper(text[i]))
            text[i] = key[text[i] - 'A'];
        else if(islower(text[i]))
            text[i] = tolower(key[text[i] - 'a']);
    }

    printf("Encrypted text: %s", text);

    return 0;
}