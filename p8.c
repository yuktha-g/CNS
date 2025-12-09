#include <stdio.h>
#include <string.h>
#include <openssl/aes.h>

int main() {
    unsigned char key[] = "0123456789abcdef";     // 16 bytes (128-bit key)
    unsigned char plaintext[AES_BLOCK_SIZE] = "welcome to ISE";
    unsigned char enc[AES_BLOCK_SIZE], dec[AES_BLOCK_SIZE];

    AES_KEY enc_key, dec_key;
    AES_set_encrypt_key(key, 128, &enc_key);
    AES_encrypt(plaintext   , enc, &enc_key);

    AES_set_decrypt_key(key, 128, &dec_key);
    AES_decrypt(enc, dec, &dec_key);

    printf("Ciphertext: ");
    for(int i=0;i<AES_BLOCK_SIZE;i++) printf("%02x", enc[i]);
    printf("\nDecrypted: %s\n", dec);
    return 0;
}
gcc aes.c -lcrypto -o aes
./aes
