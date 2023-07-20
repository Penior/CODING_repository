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
    
    complex double sinz = sin_f((0.5)*M_PI);
    double realpart = creal(sinz);
    double imagpart = cimag(sinz);
    printf("%.6g + %.6gi", realpart, imagpart);

    return 0;
}
