#include <stdio.h>
#include <openssl/des.h>

int main() {
    DES_cblock key = "12345678";
    DES_key_schedule schedule;
    DES_cblock input = "HELLO123";
    DES_cblock encrypted, decrypted;

    DES_set_key_unchecked(&key, &schedule);
    DES_ecb_encrypt(&input, &encrypted, &schedule, DES_ENCRYPT);
    DES_ecb_encrypt(&encrypted, &decrypted, &schedule, DES_DECRYPT);

    printf("Original Text: %.8s\n", input);
    printf("Encrypted Text: ");
    for (int i = 0; i < 8; i++)
        printf("%02X", encrypted[i]);
    printf("\nDecrypted Text: %.8s\n", decrypted);

    return 0;
}
