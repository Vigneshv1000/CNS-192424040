#include <stdio.h>

int gcd(int a, int b)
{
    while(b != 0)
    {
        int t = b;
        b = a % b;
        a = t;
    }

    return a;
}

int main()
{
    char text[100];
    int a, b, i;

    printf("Enter plaintext: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter values of a and b: ");
    scanf("%d%d", &a, &b);

    if(gcd(a, 26) != 1)
    {
        printf("Invalid value of a");
        return 0;
    }

    for(i = 0; text[i] != '\0'; i++)
    {
        if(text[i] >= 'A' && text[i] <= 'Z')
            text[i] = ((a * (text[i] - 'A') + b) % 26) + 'A';

        else if(text[i] >= 'a' && text[i] <= 'z')
            text[i] = ((a * (text[i] - 'a') + b) % 26) + 'a';
    }

    printf("Encrypted text: %s", text);

    return 0;
}