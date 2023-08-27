#include <stdio.h>

long long mod_pow(long long base, long long exponent, long long modulus) {
    long long result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % modulus;
        }
        base = (base * base) % modulus;
        exponent /= 2;
    }
    return result;
}

int main() {
    long long A, B, C;
    scanf("%lld %lld %lld", &A, &B, &C);

    long long result = mod_pow(A, B, C);

    printf("%ld\n", result);

    return 0;
}
