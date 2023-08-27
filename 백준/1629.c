#include <stdio.h>
#include <math.h>

int main () {

    long long int A, B, C, D;

    scanf("%lld %lld %lld", &A, &B, &C);

    D = (int)pow(A%C, 2);
    B /= 2;
    A = D;

    while (D > C) {
        for (int i = 2; i < B; i++) {
            while (B % i == 0) {
            D = pow(A%C, i);
            B /= i;
            A = D;
            }
        }
    };

    if (D < 0) {
        D += ((int)D / C) * C * -1;
        D += C;
    }

    printf("%lld", D);
}