#include <stdio.h>
#include <string.h>
#include <ctype.h>

char matrix[5][5];

// Create key matrix
void createMatrix(char key[]) {
    int used[26] = {0}, i = 0, j = 0;
    used['j' - 'a'] = 1; // treat i/j same

    for (int k = 0; key[k] != '\0'; k++) {
        char ch = tolower(key[k]);
        if (ch < 'a' || ch > 'z') continue;
        if (!used[ch - 'a']) {
            matrix[i][j++] = ch;
            used[ch - 'a'] = 1;
            if (j == 5) { j = 0; i++; }
        }
    }

    for (char ch = 'a'; ch <= 'z'; ch++) {
        if (!used[ch - 'a']) {
            matrix[i][j++] = ch;
            used[ch - 'a'] = 1;
            if (j == 5) { j = 0; i++; }
        }
    }
}

// Find positions of two letters in matrix
void findPos(char a, char b, int pos[]) {
    if (a == 'j') a = 'i';
    if (b == 'j') b = 'i';
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++) {
            if (matrix[i][j] == a) { pos[0] = i; pos[1] = j; }
            if (matrix[i][j] == b) { pos[2] = i; pos[3] = j; }
        }
}

// Encrypt text using Playfair
void encrypt(char text[]) {
    int len = strlen(text);

    // Preprocess text: remove spaces, insert 'x' for repeats
    char clean[100]; int k = 0;
    for (int i = 0; i < len; i++)
        if (isalpha(text[i])) clean[k++] = tolower(text[i]);
    clean[k] = '\0';

    for (int i = 0; i < k; i += 2) {
        if (clean[i + 1] == '\0') clean[i + 1] = 'z';
        else if (clean[i] == clean[i + 1]) {
            for (int j = k; j > i + 1; j--) clean[j] = clean[j - 1];
            clean[i + 1] = 'x';
            k++;
        }
    }

    printf("\nCipher text: ");
    int pos[4];
    for (int i = 0; i < k; i += 2) {
        findPos(clean[i], clean[i + 1], pos);
        // same row
        if (pos[0] == pos[2])
            printf("%c%c", matrix[pos[0]][(pos[1] + 1) % 5], matrix[pos[0]][(pos[3] + 1) % 5]);
        // same column
        else if (pos[1] == pos[3])
            printf("%c%c", matrix[(pos[0] + 1) % 5][pos[1]], matrix[(pos[2] + 1) % 5][pos[1]]);
        // rectangle rule
        else
            printf("%c%c", matrix[pos[0]][pos[3]], matrix[pos[2]][pos[1]]);
    }
    printf("\n");
}

int main() {
    char key[50], text[100];
    printf("Enter key: ");
    gets(key);
    printf("Enter plaintext: ");
    gets(text);

    createMatrix(key);
    encrypt(text);
    return 0;
}
