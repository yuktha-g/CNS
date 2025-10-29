#include <stdio.h>
#include <string.h>

void hillEncrypt(char msg[], int key[2][2]) {
    int i, j, k;
    int len = strlen(msg);
    if (len % 2 != 0) msg[len++] = 'X'; // pad if odd length

    printf("Encrypted message: ");
    for (i = 0; i < len; i += 2) {
        int p1 = msg[i] - 'A';
        int p2 = msg[i+1] - 'A';
        int c1 = (key[0][0]*p1 + key[0][1]*p2) % 26;
        int c2 = (key[1][0]*p1 + key[1][1]*p2) % 26;
        printf("%c%c", c1 + 'A', c2 + 'A');
    }
    printf("\n");
}

int main() {
    int key[2][2] = {{1, 2}, {3, 4}};
    char msg[100] = "HELLO";
    
    printf("Original: %s\n", msg);
    hillEncrypt(msg, key);

    return 0;
}
