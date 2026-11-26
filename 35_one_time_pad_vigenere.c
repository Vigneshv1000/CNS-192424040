#include <stdio.h>
#include <string.h>

int main() {
    char text[100];
    int key[100], n;

    printf("Enter plaintext (uppercase letters): ");
    scanf("%99s", text);

    n = (int)strlen(text);

    printf("Enter %d key values (0-25): ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &key[i]);

    printf("Encrypted Text: ");
    for (int i = 0; i < n; i++)
        printf("%c", ((text[i] - 'A' + key[i]) % 26) + 'A');

    printf("\n");
    return 0;
}
