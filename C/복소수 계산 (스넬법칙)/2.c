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

int main() {
    
    double realpart, imagpart = 0;
    int choice1 = 0;

    printf("\n복소수의 실수부를 입력하세요.\n");
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
    complex double z1 = realpart + imagpart * i;
    complex double sinz1 = sin_f(z1);

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

    double sin_realpart = creal(sinz1);
    double sin_imagpart = cimag(sinz1);

    if (sin_imagpart >= 0) {
        printf("해당 각의 사인값: %.6g + %.6g i\n", sin_realpart, sin_imagpart);
    }
    else {
        printf("해당 각의 사인값: %.6g - %.6g i\n", sin_realpart, -sin_imagpart);
    }

    return 0;
}
