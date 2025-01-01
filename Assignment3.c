#include <stdio.h>

long long modularExponentiation(int base, int exp, int mod) {
    long long result = 1;
    base = base % mod;

    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

int main() {
    int B, N, M;

    do {
        printf("Enter the modulus M (greater than 1): ");
        scanf("%d", &M);
        if (M <= 1) {
            printf("Invalid input. M must be greater than 1.\n");
        }
    } while (M <= 1);

    printf("Enter the base B (positive integer): ");
    scanf("%d", &B);
    
    do {
        printf("Enter the exponent N (non-negative integer): ");
        scanf("%d", &N);
        if (N < 0) {
            printf("Invalid input. N must be a non-negative integer.\n");
        }
    } while (N < 0);

    long long result = modularExponentiation(B, N, M);
    printf("Result: %lld\n", result);

    return 0;
}
