#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char text[100];
    int key[100], i, n;

    printf("Enter plaintext: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter number of key values: ");
    scanf("%d", &n);

    printf("Enter key values:\n");

    for(i = 0; i < n; i++)
        scanf("%d", &key[i]);

    int j = 0;

    for(i = 0; text[i] != '\0'; i++)
    {
        if(isalpha(text[i]))
        {
            if(j >= n)
            {
                printf("Insufficient key values\n");
                return 0;
            }

            text[i] = (toupper(text[i]) - 'A' +
                       key[j]) % 26 + 'A';

            j++;
        }
    }

    printf("Encrypted text: %s\n", text);

    return 0;
}