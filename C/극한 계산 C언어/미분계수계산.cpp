#include <math.h>
#include <iostream>
using namespace std;

/*함수 : y = x^4 + 2x^2 + 5x*/
double f(double x) {
    return pow(x, 4) + 2 * pow(x , 2) + 5 * x;
}

double LIMIT_f(double x) {
    double A = 0, B = 0, delX = 0;
    for(double i = 1; fabs(f(x + i) - f(x - i)) >= 0.0001; i /= 10) {
        A = f(x + i);
        B = f(x - i);
        delX = i;
    }

    return (A - B) / (2 * delX);
}

int main () {
    cout << LIMIT_f(2) << endl;
    return 0;    
}