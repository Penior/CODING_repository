#include <stdio.h>
#include <math.h>

/*함수 : y = x^2*/
double f(double x) {
    return x * x;
}

float LIMIT_f(double x) {
    double A = 0, B = 0;
    for(double i = 1; fabs(f(x + i) - f(x - i)) >= 0.0001; i /= 10) {
        A = f(x + i);
        B = f(x - i);
    }

    return (A + B) / 2;
}

int main () {

    printf("%g", LIMIT_f(3));
    return 0;    
}