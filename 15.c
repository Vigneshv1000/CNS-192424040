#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char cipher[500], plain[500];
    int freq[26] = {0};
    int i, j, key, top;

    printf("Enter ciphertext:\n");
    fgets(cipher, sizeof(cipher), stdin);

    printf("Enter number of possible plaintexts: ");
    scanf("%d", &top);

    for(i = 0; cipher[i] != '\0'; i++)
        if(isalpha(cipher[i]))
            freq[toupper(cipher[i]) - 'A']++;

    int count[26];

    for(i = 0; i < 26; i++)
        count[i] = freq[i];

    printf("\nPossible plaintexts:\n");

    for(int k = 0; k < top && k < 26; k++)
    {
        int max = -1;
        int letter = 0;

        for(i = 0; i < 26; i++)
        {
            if(count[i] > max)
            {
                max = count[i];
                letter = i;
            }
        }

        count[letter] = -1;

        key = (letter - 4 + 26) % 26;

        for(i = 0; cipher[i] != '\0'; i++)
        {
            if(isupper(cipher[i]))
                plain[i] = (cipher[i] - 'A' - key + 26) % 26 + 'A';

            else if(islower(cipher[i]))
                plain[i] = (cipher[i] - 'a' - key + 26) % 26 + 'a';

            else
                plain[i] = cipher[i];
        }

        plain[i] = '\0';

        printf("\nKey = %d\n", key);
        printf("Plaintext = %s\n", plain);
    }

    return 0;
}