#include <stdio.h>
#include <string.h>

int main() {
    char text[1000], result[1000];

    printf("Enter ciphertext: ");
    fgets(text, sizeof(text), stdin);

    for (int k = 0; k < 26; k++) {
        int i;
        for (i = 0; text[i]; i++) {
            if (text[i] >= 'A' && text[i] <= 'Z')
                result[i] = (text[i] - 'A' - k + 26) % 26 + 'A';
            else if (text[i] >= 'a' && text[i] <= 'z')
                result[i] = (text[i] - 'a' - k + 26) % 26 + 'a';
            else
                result[i] = text[i];
        }
        result[i] = '\0';
        printf("\nKey %d: %s", k, result);
    }

    return 0;
}
