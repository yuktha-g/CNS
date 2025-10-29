#include <stdio.h>
#include <string.h>

int main() {
    char pt[100] = "wearediscoveredsaveyourself";
    char key[100] = "deceptive";
    char ct[100], rt[100];
    int i, keyLen = strlen(key), textLen = strlen(pt);

    // Repeat key to match plaintext length
    for (i = 0; i < textLen; i++)
        key[i] = key[i % keyLen];
    key[i] = '\0';

    printf("Repeated Key: %s\n", key);

    // Encryption
    for (i = 0; i < textLen; i++)
        ct[i] = ((pt[i] - 'a') + (key[i] - 'a')) % 26 + 'a';
    ct[i] = '\0';
    printf("Encrypted text: %s\n", ct);

    // Decryption
    for (i = 0; i < textLen; i++)
        rt[i] = ((ct[i] - key[i] + 26) % 26) + 'a';
    rt[i] = '\0';
    printf("Decrypted text: %s\n", rt);

    return 0;
}
