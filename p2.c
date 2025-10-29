#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define ALPHABET_SIZE 26

// Encrypt function
char* encrypt(const char *text, const char *key) {
    static char cipher[100];
    for (int i = 0; text[i] != '\0'; i++) {
        if (isupper(text[i]))
            cipher[i] = key[text[i] - 'A'];      // Uppercase letters
        else if (islower(text[i]))
            cipher[i] = tolower(key[text[i] - 'a']); // Lowercase letters
        else
            cipher[i] = text[i]; // Leave spaces, etc.
    }
    cipher[strlen(text)] = '\0';
    return cipher;
}

// Decrypt function
char* decrypt(const char *cipher, const char *key) {
    static char plain[100];
    for (int i = 0; cipher[i] != '\0'; i++) {
        if (isupper(cipher[i])) {
            for (int j = 0; j < ALPHABET_SIZE; j++)
                if (key[j] == cipher[i])
                    plain[i] = 'A' + j;
        } else if (islower(cipher[i])) {
            for (int j = 0; j < ALPHABET_SIZE; j++)
                if (tolower(key[j]) == cipher[i])
                    plain[i] = 'a' + j;
        } else
            plain[i] = cipher[i];
    }
    plain[strlen(cipher)] = '\0';
    return plain;
}

int main() {
    const char key[] = "QWERTYUIOPASDFGHJKLZXCVBNM";
    const char text[] = "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG";

    printf("Plaintext : %s\n", text);
    char *cipher = encrypt(text, key);
    printf("Ciphertext: %s\n", cipher);
    char *plain = decrypt(cipher, key);
    printf("Decrypted : %s\n", plain);

    return 0;
}

