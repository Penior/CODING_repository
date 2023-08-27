#include <stdio.h>
#include <inttypes.h>

int main () {
    unsigned int S;
    long long int i = 1;

    long long int S1 = (i * (i + 1)) / 2;

    scanf("%d", &S);

    while(S1 <= S) {
        i++;
        S1 = (i * (i + 1)) / 2;
    }

    printf("%I64d", i - 1);
}