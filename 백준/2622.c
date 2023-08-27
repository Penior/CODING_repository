#include <stdio.h>

int CalculateTriangle(int N, int S1, int S2, int S3) {
    int Triangle = 0;
    while (S1 >= S3) {
        Triangle += ((S2 - S3) / 2) + 1;
        S1 -= 1;
        S2 = S1;
        S3 = N - S1 - S2;
    }
    
    printf("%d", Triangle);
    }

int main () {
    int N;
    scanf("%d", &N);

    int S1, S2, S3;

    if(N % 2 == 0) {
        S1 = N/2 - 1;
        S2 = N/2 - 1;
        S3 = N - S1 - S2;
    }
    else {
        S1 = N/2;
        S2 = N/2;
        S3 = N - S1 - S2;
    }

    CalculateTriangle(N, S1, S2, S3);

    return 0;
}