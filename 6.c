#include <stdio.h>
#include <string.h>

int modInverse(int a)
{
    int i;

    for(i = 1; i < 26; i++)
        if((a * i) % 26 == 1)
            return i;

    return -1;
}

int main()
{
    char cipher[100];
    int a, b, inv, i;

    printf("Enter ciphertext: ");
    fgets(cipher, sizeof(cipher), stdin);

    printf("Enter values of a and b: ");
    scanf("%d%d", &a, &b);

    inv = modInverse(a);

    if(inv == -1)
    {
        printf("Invalid key");
        return 0;
    }

    for(i = 0; cipher[i] != '\0'; i++)
    {
        if(cipher[i] >= 'A' && cipher[i] <= 'Z')
            cipher[i] = (inv * (cipher[i] - 'A' - b + 26)) % 26 + 'A';
    }

    printf("Decrypted text: %s", cipher);

    return 0;
}