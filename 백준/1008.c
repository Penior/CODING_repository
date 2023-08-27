#include <stdio.h>

double divide(int a, int b) {
    return (double)a / (double)b;
}
int main () {

    int A , B;
    scanf("%d %d", &A, &B);
    printf("%.10g", divide(A, B));
}