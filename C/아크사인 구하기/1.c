#include <stdio.h>
#include <math.h>
#define pi 3.14159265358979323846264338432795028

float returnarcsin(float sin_value) {
    double a = 0;
    double deltaX = 1;
    double a1 = a + deltaX * (sin_value - sin(a));
    deltaX = a + deltaX * (sin_value - sin(a));
    a = a1;

    for(int i = 0; abs(sin_value - sin(a)) < 0.000001; i++) {
        double a1 = a + deltaX * (sin_value - sin(a));
        deltaX = a + deltaX * (sin_value - sin(a));
        a = a1;
    }

    return sin(a);
}
int main() {
    float sin_value;
    printf("사인값을 제시해주세요.\n : ");
    scanf("%f", &sin_value);

    printf("%f",returnarcsin(sin_value));
    return 0;
}