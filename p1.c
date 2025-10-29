#include <stdio.h>

// Function to shift characters by key
void caesar(char text[], int key) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] >= 'a' && text[i] <= 'z')
            text[i] = 'a' + (text[i] - 'a' + key + 26) % 26; // lowercase
        else if (text[i] >= 'A' && text[i] <= 'Z')
            text[i] = 'A' + (text[i] - 'A' + key + 26) % 26; // uppercase
    }
}

int main() {
    char msg[] = "hello how are u";
    int key = 3;

    printf("Original : %s\n", msg);

    // Encrypt
    caesar(msg, key);
    printf("Encrypted: %s\n", msg);

    // Decrypt
    caesar(msg, -key);
    printf("Decrypted: %s\n", msg);

    return 0;
}
