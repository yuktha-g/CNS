#include <stdio.h>

#define P 23
#define G 5

int mod_exp(int base, int exp, int mod) {
    int result = 1;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}

int main() {
    // These are the values rand() generated earlier (to reproduce output = 1)
    int a = 3;   // client private key
    int b = 7;   // server private key

    int A = mod_exp(G, a, P);  // client public key
    int B = mod_exp(G, b, P);  // server public key

    int S_client = mod_exp(B, a, P);
    int S_server = mod_exp(A, b, P);

    printf("Client shared secret: %d\n", S_client);
    printf("Server shared secret: %d\n", S_server);

    return 0;
}
