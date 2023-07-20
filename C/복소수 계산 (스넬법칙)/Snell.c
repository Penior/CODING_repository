#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <conio.h>

#define i I

// 사인값 구하기 //
complex double sin_f(complex double x) {
    complex double result = ((cexp(i * x) - cexp(-i * x)) / (2*i));
    return result;
}

// 각 묻고 사인값 출력 //
void outputsinz(complex double *z1, complex double *sinz1) {
    double realpart, imagpart = 0;
    int choice1 = 0;

    printf("1. 파이의 계수로 입력합니다.\n");
    printf("2. 일반적인 실수로 입력합니다.\n");
    printf("선택: ");
    scanf("%d", &choice1);

    // 실수 부분 작성 //
    if (choice1 == 1) {
        printf("파이의 계수를 입력하세요: ");
        scanf("%lf", &realpart);
        printf("입력된 값: %gπ\n", realpart);
        realpart *= M_PI;
    } else if (choice1 == 2) {
        printf("일반적인 실수를 입력하세요: ");
        scanf("%lf", &realpart);
        printf("입력된 값: %g\n", realpart);
    } else {
        printf("잘못된 선택입니다.\n");
        getch();
        exit(0);
    }

    // 허수 부분 작성 //
    int choice2 = 0;
    printf("\n복소수의 허수부를 입력하세요.\n");
    printf("1. 파이의 계수로 입력합니다.\n");
    printf("2. 일반적인 실수로 입력합니다.\n");
    printf("선택: ");
    scanf("%d", &choice2);

    if (choice2 == 1) {
        printf("파이의 계수를 입력하세요: ");
        scanf("%lf", &imagpart);
        printf("입력된 값: %gπ\n", imagpart);
        imagpart *= M_PI;
    } else if (choice2 == 2) {
        printf("일반적인 실수를 입력하세요: ");
        scanf("%lf", &imagpart);
        printf("입력된 값: %g\n", imagpart);
    } else {
        printf("잘못된 선택입니다.\n");
        getch();
        exit(0);
    }

    // 각 출력 //
    *z1 = realpart + imagpart * i;
    *sinz1 = sin_f(*z1);

    printf("각의 크기: ");
    if (choice1 == 1) {
        printf("%.6gπ", realpart/M_PI );
    } else {
        printf("%.6g", realpart);
    }

    if (choice2 == 1) {
        if (imagpart >= 0) {
        printf(" + %.6gπ i\n", imagpart/M_PI);
        }
        else {
        printf(" - %.6gπ i\n", -imagpart/M_PI);
        }
    } else {
        if (imagpart >= 0) {
        printf(" + %.6g i\n", imagpart);
        }
        else {
        printf(" - %.6g i\n", -imagpart);
        }
    }

    // 오차 잡기 //
    double sin_realpart = creal(*sinz1);
    double sin_imagpart = cimag(*sinz1);

    if (fabs(sin_realpart) < 1e-6) {
        sin_realpart = 0.0;
    }
    if (fabs(sin_imagpart) < 1e-6) {
        sin_imagpart = 0.0;
    } 

    if (sin_imagpart >= 0) {
        printf("해당 각의 사인값: %.6g + %.6g i\n", sin_realpart, sin_imagpart);
    }
    else {
        printf("해당 각의 사인값: %.6g - %.6g i\n", sin_realpart, -sin_imagpart);
    }
}

int main() {
    complex double z1, sinz1;
    printf("첫 번째 복소수 각의 실수부를 입력합니다.\n");
    outputsinz(&z1, &sinz1);

    printf("\n");

    complex double z2, sinz2;
    printf("두 번째 복소수 각의 실수부를 입력합니다.\n");
    outputsinz(&z2, &sinz2);

    double realpart_resultsindivide = creal(sinz1/sinz2);
    double imagpart_resultsindivide = cimag(sinz1/sinz2);

    if (fabs(realpart_resultsindivide) < 1e-6) {
        realpart_resultsindivide = 0.0;
    }
    if (fabs(imagpart_resultsindivide) < 1e-6) {
        imagpart_resultsindivide = 0.0;
    }


    printf("\n첫 번째 각이 빛의 입사각이고, 두 번쨰 각이 빛의 굴절각일 때\n(첫 번쨰 매질에서의 빛의 속력) : (두 번째 매질에서의 빛의 속력) = ");
    if (imagpart_resultsindivide > 0) {
    printf("%.6g + %.6g i : 1", realpart_resultsindivide, imagpart_resultsindivide);
    } else if (imagpart_resultsindivide == 0) {
    printf("%.6g : 1", realpart_resultsindivide);
    } else if (imagpart_resultsindivide < 0) {
    printf("%.6g - %.6g i : 1", realpart_resultsindivide, -imagpart_resultsindivide);
    }

    getch();
    return 0;

}
