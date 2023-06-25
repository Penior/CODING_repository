#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>

// 최소제곱법을 적용하여 선형 모델의 기울기와 절편을 계산
void leastSquares(double x[], double y[], int n, double* slope, double* intercept) {
    double sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0;

    for (int i = 0; i < n; i++) {
        sumX += x[i];
        sumY += y[i];
        sumXY += x[i] * y[i];
        sumX2 += x[i] * x[i];
    }

    double meanX = sumX / n;
    double meanY = sumY / n;

    *slope = (sumXY - n * meanX * meanY) / (sumX2 - n * meanX * meanX);
    *intercept = meanY - *slope * meanX;
}

float generateRandomFloat(float min, float max) {
    return min + ((float)rand() / RAND_MAX) * (max - min);
}

int main() {
    double x[700];
    double y[700];
    srand(time(NULL));

    for (int i = 0; i < 700; i++) {
        float xnum = generateRandomFloat(0.0f, 1000.0f);

        float ynum;
        if (xnum < 150.0f) {
            ynum = generateRandomFloat(0.0f, xnum + 150.0f);
        } else if (xnum > 850.0f) {
            ynum = generateRandomFloat(xnum - 150.0f, 1000.0f);
        } else {
            ynum = generateRandomFloat(xnum - 150.0f, xnum + 150.0f);
        }
        x[i] = xnum;
        y[i] = ynum;
    }

    FILE* file = fopen("data.txt", "w");
    if (file == NULL) {
        printf("Failed to open file.\n");
        return 1;
    }

    for (int i = 0; i < 700; i++) {
        fprintf(file, "%f %f\n", x[i], y[i]);
    }

    fclose(file);

    // 최소제곱법을 적용하여 선형 모델 계산
    double slope, intercept;
    leastSquares(x, y, 700, &slope, &intercept);

    FILE* script = fopen("script.gp", "w");
    if (script == NULL) {
        printf("Failed to open script file.\n");
        return 1;
    }

    fprintf(script, "set title 'Linear Regression'\n");
    fprintf(script, "set xlabel 'x'\n");
    fprintf(script, "set ylabel 'y'\n");
    fprintf(script, "plot 'data.txt' with points, %f * x + %f\n", slope, intercept);
    fprintf(script, "pause -1 'Press any key to exit'\n");

    fclose(script);

    system("gnuplot script.gp");

    return 0;
}