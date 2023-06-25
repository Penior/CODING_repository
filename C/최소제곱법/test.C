#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float generateRandomFloat(float min, float max) {
    return min + ((float)rand() / RAND_MAX) * (max - min);
}

int main() {
    srand(time(NULL));
    float xnum = generateRandomFloat(0.0f, 1000.0f);

    float ynum;
    if (xnum < 150.0f) {
        ynum = generateRandomFloat(0.0f, xnum + 150.0f);
    } else if (xnum > 850.0f) {
        ynum = generateRandomFloat(xnum - 150.0f, 1000.0f);
    } else {
        ynum = generateRandomFloat(xnum - 150.0f, xnum + 150.0f);
    }

    printf("xnum: %.2f\n", xnum);
    printf("ynum: %.2f\n", ynum);

    return 0;
}