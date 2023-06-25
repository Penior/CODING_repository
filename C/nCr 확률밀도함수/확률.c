#include <stdio.h>
#include <math.h>
#include <windows.h>
int main ()
{
    /* 묻기 */
    unsigned __int64 A = 1;
    int n = 1;
    double Per = 0.00;
    double SPer = 0.00;
    int MODE = 1;
    double SUM = 0.00;
    printf("시도 횟수는 몇 번으로 하시겠습니까? (60 이하를 권장합니다.)\nㄴ ");
    scanf("%d", &n);
    printf("\n\nMODE 1 : 경우의 수 나열, 2 : 확률 나열, 3 : 확률 나열 백분율로 나타내기, 4 : 누적 분포 함수, 5: 누적 분포 함수 백분율\n무슨 모드를 사용하시겠습니까?\nㄴ ");
    scanf("%d", &MODE);
    if(MODE > 1) {
        printf("\n\n성공 확률은 어떻게 하시겠습니까? (0=<p=<1)\nㄴ ");
        scanf("%lf", &SPer); 
    }
    /* MODE 1 : 경우의 수 나열, 2 : 확률 나열, 3 : 확률 나열 백분율로 나타내기, 4 : 누적 분포 함수 */
    printf("\n\n");
    if(MODE==1){
        printf("%dC0 = %lld\n", n, A);
        for(int i=1;i<n+1;i++) {
            A = A * (n+1-i) / i;
            printf("%dC%d = %lld\n",n, i, A);
        }
    }
    if(MODE==2){
        printf("0 Success of %d Trial's Percentage : %.20g\n", n, A*pow(SPer, 0)*pow(1-SPer, n));
        SUM = (A*pow(SPer, 0)*pow(1-SPer, n)) + SUM;
        for(int i=1;i<n+1;i++) {
            A = A * (n+1-i) / i;
            SUM = (A*pow(SPer, i)*pow(1-SPer, n-i)) + SUM;
            printf("%d Success of %d Trial's Percentage : %.20g\n", i, n, A*pow(SPer, i)*pow(1-SPer, n-i));
        }
        printf("Sum of Percentage : %.20g%%. Error Range : %.20g%%", SUM, 1-SUM);
    }
    if(MODE==3){
        printf("0 Success of %d Trial's Percentage : %.20g%%\n",n, A*pow(SPer, 0)*pow(1-SPer, n)*100);
        SUM = (A*pow(SPer, 0)*pow(1-SPer, n)*100) + SUM;
        for(int i=1;i<n+1;i++) {
            A = A * (n+1-i) / i;
            SUM = (A*pow(SPer, i)*pow(1-SPer, n-i)*100) + SUM;
            printf("%d Success of %d Trial's Percentage : %.20g%%\n", i, n, A*pow(SPer, i)*pow(1-SPer, n-i)*100);
        }
        printf("Sum of Percentage : %.20g%%. Error Range : %.20g%%", SUM, 100-SUM);
    }
    if(MODE==4){
        for(int i=1;i<n+1;i++) {
            A = A * (n+1-i) / i;
            Per = A*pow(SPer, i)*pow(1-SPer, n-i) + Per;
            printf("%d↓ Success of %d Trial's Percentage : %.20g\n", i-1, n, Per);
        }
        printf("%d↓ Success of %d Trial's Percentage : 1\n", n, n);
    }
    if(MODE==5){
        for(int i=1;i<n+1;i++) {
            A = A * (n+1-i) / i;
            Per = A*pow(SPer, i)*pow(1-SPer, n-i) + Per;
            printf("%d↓ Success of %d Trial's Percentage : %.20g%%\n", i-1, n, Per*100);
        }
        printf("%d↓ Success of %d Trial's Percentage : 100%%\n", n, n);
    }
printf("\n");
system("pause");
return 0;
}