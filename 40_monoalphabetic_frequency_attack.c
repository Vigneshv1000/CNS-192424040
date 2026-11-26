#include <stdio.h>

int main() {
    char text[1000];
    char freq[] = "ETAOINSHRDLCUMWFGYPBVKJXQZ";
    int count[26] = {0};
    int used[26] = {0};
    int map[26];

    printf("Enter ciphertext: ");
    fgets(text, sizeof(text), stdin);

    for (int i = 0; text[i]; i++) {
        if (text[i] >= 'A' && text[i] <= 'Z')
            count[text[i] - 'A']++;
        else if (text[i] >= 'a' && text[i] <= 'z')
            count[text[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        int max = -1, pos = 0;
        for (int j = 0; j < 26; j++) {
            if (!used[j] && count[j] > max) {
                max = count[j];
                pos = j;
            }
        }
        used[pos] = 1;
        map[pos] = freq[i];
    }

    printf("Possible Plaintext: ");
    for (int i = 0; text[i]; i++) {
        if (text[i] >= 'A' && text[i] <= 'Z')
            printf("%c", map[text[i] - 'A']);
        else if (text[i] >= 'a' && text[i] <= 'z')
            printf("%c", map[text[i] - 'a'] + 32);
        else
            printf("%c", text[i]);
    }

    return 0;
}
