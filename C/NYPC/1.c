#include <stdio.h>
#include <string.h>

int N = 0;
int K = 0;
int T = 0;
int S = 0;

int main() {
    scanf("%d", &N);

    char list[N][16];

    for (int i = 0; i < N; i++) {
        scanf("%s", list[i]);
    }

    scanf("%d", &K);
    char experienced[K][16];
    for (int i = 0; i < K; i++) {
        scanf("%s", experienced[i]);
    }

    int savearr[N];
    int count = 0;

    for (int i = 0; i < N; i++) {
        S = 0;
        for (int j = 0; j < K; j++) {
            if (strcmp(list[i], experienced[j]) == 0) {
                S += 1;
            }
        }
        if (S == 0) {
            savearr[count] = i;
            count += 1;
        }
    }

    printf("%d\n", count);
    for (int i = 0; i < count; i++){
        printf("%s\n", list[savearr[i]]);
    }
}