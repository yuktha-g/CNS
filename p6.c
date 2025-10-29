#include <stdio.h>

// Function to perform (base^exp) % mod efficiently
long long power(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

// RSA encryption: C = (M^e) mod n
long long encrypt(long long M, long long e, long long n) {
    return power(M, e, n);
}

// RSA decryption: M = (C^d) mod n
long long decrypt(long long C, long long d, long long n) {
    return power(C, d, n);
}

int main() {
    long long p = 61, q = 53;
    long long n = p * q;               // n = 3233
    long long phi = (p - 1) * (q - 1); // φ(n) = 3120
    long long e = 17;                  // Public key exponent
    long long d = 2753;                // Private key exponent

    long long plaintext = 123;         // Example message
    printf("Plaintext: %lld\n", plaintext);

    long long ciphertext = encrypt(plaintext, e, n);
    printf("Encrypted message: %lld\n", ciphertext);

    long long decrypted = decrypt(ciphertext, d, n);
    printf("Decrypted message: %lld\n", decrypted);

    return 0;
}
