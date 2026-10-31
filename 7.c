#include <stdio.h>
#include <string.h>

int main()
{
    char cipher[500];

    char key[] = "abcdefghijklmnopqrstuvwxyz";
    char value[] = "abcdefghijklmnopqrstuvwxyz";

    printf("Enter ciphertext:\n");
    fgets(cipher, sizeof(cipher), stdin);

    printf("Enter cipher alphabet: ");
    scanf("%26s", value);

    for(int i = 0; cipher[i] != '\0'; i++)
    {
        for(int j = 0; j < 26; j++)
        {
            if(cipher[i] == value[j])
            {
                cipher[i] = key[j];
                break;
            }
        }
    }

    printf("Decrypted text:\n%s", cipher);

    return 0;
}