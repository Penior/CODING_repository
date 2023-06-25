#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int main() {
    srand(time(NULL));

    double x, y;

    // x 값 생성
    x = (rand() % 30001) / 100.0; // 0부터 300까지 소수 두 번째 자리까지의 임의의 값 생성

    if (x > 275) {
        // x가 275를 초과할 경우
        y = (rand() % ((int)(300 - x) * 100 + 1)) / 100.0 + x - 25;
    } else if (x < 25) {
        // x가 25 미만일 경우
        y = (rand() % ((int)(x + 25) * 100 + 1)) / 100.0;
    } else {
        // x가 25 이상 275 이하인 경우
        y = (rand() % 5101) / 100.0 + x - 25;
    }

    // x와 y 값 출력
    printf("x: %.2lf\n", x);
    printf("y: %.2lf\n", y);

    return 0;
}