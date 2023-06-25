#include <stdio.h>
#include <math.h>
main() {
    int SET = 0;
    double DOWN = 0;
    printf("밑 얼마? ");
    scanf("%lf", &DOWN);
    printf("\n몇 제곱까지 계산? ");
    scanf("%d", &SET);
    for(int i=0; i<SET; i++) {
    printf("\n%d) %lf",i+1,pow(DOWN,i));
    }
    scanf("%d",&SET);
}