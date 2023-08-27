#include <stdio.h>

int main()
{   
    int T;
    scanf("%d", &T);
    int A[T], B[T], K[T];

    for (int i = 0; i < T; i++)
    {
        scanf("%d %d", &A[i], &B[i]);
    }

    for(int i = 0; i < T; i++) {
        K[i] = 1;
        for(int j = 2; j <= A[i] && j <= B[i]; j++) {
            if(A[i] % j == 0 && B[i] % j == 0) {
                while(A[i] % j == 0 && B[i] % j == 0) {
                    K[i] *= j;
                    A[i] /= j;
                    B[i] /= j;
                }
            }
        }
        printf("%d\n", K[i] * A[i] * B[i]);
    }

    
    return 0;
}
