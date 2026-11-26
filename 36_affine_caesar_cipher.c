#include <stdio.h>

int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main() {
    char text[100];
    int a, b;

    printf("Enter plaintext (uppercase letters): ");
    scanf("%99s", text);

    printf("Enter a and b: ");
    scanf("%d%d", &a, &b);

    if (gcd(a, 26) != 1) {
        printf("Invalid key. Choose a value of a coprime with 26.\n");
        return 0;
    }

    printf("Encrypted Text: ");
    for (int i = 0; text[i] != '\0'; i++) {
        int p = text[i] - 'A';
        int c = (a * p + b) % 26;
        printf("%c", c + 'A');
    }

    printf("\n");
    return 0;
}
