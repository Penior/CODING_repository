#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <conio.h>

#define i I

// ���ΰ� ���ϱ� //
complex double sin_f(complex double x) {
    complex double result = ((cexp(i * x) - cexp(-i * x)) / (2*i));
    return result;
}

// �� ���� ���ΰ� ��� //
void outputsinz(complex double *z1, complex double *sinz1) {
    double realpart, imagpart = 0;
    int choice1 = 0;

    printf("1. ������ ����� �Է��մϴ�.\n");
    printf("2. �Ϲ����� �Ǽ��� �Է��մϴ�.\n");
    printf("����: ");
    scanf("%d", &choice1);

    // �Ǽ� �κ� �ۼ� //
    if (choice1 == 1) {
        printf("������ ����� �Է��ϼ���: ");
        scanf("%lf", &realpart);
        printf("�Էµ� ��: %g��\n", realpart);
        realpart *= M_PI;
    } else if (choice1 == 2) {
        printf("�Ϲ����� �Ǽ��� �Է��ϼ���: ");
        scanf("%lf", &realpart);
        printf("�Էµ� ��: %g\n", realpart);
    } else {
        printf("�߸��� �����Դϴ�.\n");
        getch();
        exit(0);
    }

    // ��� �κ� �ۼ� //
    int choice2 = 0;
    printf("\n���Ҽ��� ����θ� �Է��ϼ���.\n");
    printf("1. ������ ����� �Է��մϴ�.\n");
    printf("2. �Ϲ����� �Ǽ��� �Է��մϴ�.\n");
    printf("����: ");
    scanf("%d", &choice2);

    if (choice2 == 1) {
        printf("������ ����� �Է��ϼ���: ");
        scanf("%lf", &imagpart);
        printf("�Էµ� ��: %g��\n", imagpart);
        imagpart *= M_PI;
    } else if (choice2 == 2) {
        printf("�Ϲ����� �Ǽ��� �Է��ϼ���: ");
        scanf("%lf", &imagpart);
        printf("�Էµ� ��: %g\n", imagpart);
    } else {
        printf("�߸��� �����Դϴ�.\n");
        getch();
        exit(0);
    }

    // �� ��� //
    *z1 = realpart + imagpart * i;
    *sinz1 = sin_f(*z1);

    printf("���� ũ��: ");
    if (choice1 == 1) {
        printf("%.6g��", realpart/M_PI );
    } else {
        printf("%.6g", realpart);
    }

    if (choice2 == 1) {
        if (imagpart >= 0) {
        printf(" + %.6g�� i\n", imagpart/M_PI);
        }
        else {
        printf(" - %.6g�� i\n", -imagpart/M_PI);
        }
    } else {
        if (imagpart >= 0) {
        printf(" + %.6g i\n", imagpart);
        }
        else {
        printf(" - %.6g i\n", -imagpart);
        }
    }

    // ���� ��� //
    double sin_realpart = creal(*sinz1);
    double sin_imagpart = cimag(*sinz1);

    if (fabs(sin_realpart) < 1e-6) {
        sin_realpart = 0.0;
    }
    if (fabs(sin_imagpart) < 1e-6) {
        sin_imagpart = 0.0;
    } 

    if (sin_imagpart >= 0) {
        printf("�ش� ���� ���ΰ�: %.6g + %.6g i\n", sin_realpart, sin_imagpart);
    }
    else {
        printf("�ش� ���� ���ΰ�: %.6g - %.6g i\n", sin_realpart, -sin_imagpart);
    }
}

int main() {
    complex double z1, sinz1;
    printf("ù ��° ���Ҽ� ���� �Ǽ��θ� �Է��մϴ�.\n");
    outputsinz(&z1, &sinz1);

    printf("\n");

    complex double z2, sinz2;
    printf("�� ��° ���Ҽ� ���� �Ǽ��θ� �Է��մϴ�.\n");
    outputsinz(&z2, &sinz2);

    double realpart_resultsindivide = creal(sinz1/sinz2);
    double imagpart_resultsindivide = cimag(sinz1/sinz2);

    if (fabs(realpart_resultsindivide) < 1e-6) {
        realpart_resultsindivide = 0.0;
    }
    if (fabs(imagpart_resultsindivide) < 1e-6) {
        imagpart_resultsindivide = 0.0;
    }


    printf("\nù ��° ���� ���� �Ի簢�̰�, �� ���� ���� ���� �������� ��\n(ù ���� ���������� ���� �ӷ�) : (�� ��° ���������� ���� �ӷ�) = ");
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
