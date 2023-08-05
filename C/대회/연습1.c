#include <stdio.h>
#include <stdlib.h>

int N, M;

int main() {
    scanf("%d %d", &N, &M);
    int town[N][N];
    for(int i =0; i < N; i++) {
        for(int j =0; j < N; j++){
            scanf("%d", &town[i][j]);
        }
    }
    
    int maximum = 0;
    int sum;
    
    /* 십자 */
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) {
            sum = 0;
            for(int h = 0; h <= M; h++){
                if (h == 0) {
                    sum += town[i][j];
                } 
                else {
                    if(i - h >= 0) {
                        sum += town[i - h][j];
                    }
                    if(i + h < N) {
                        sum += town[i + h][j];
                    }
                    if(j - h >= 0) {
                        sum += town[i][j - h];
                    }
                    if(j + h < N) {
                        sum += town[i][j + h];
                    }
                }
            }
            if (sum > maximum) {
                maximum = sum;
            }
            
        }
    }
    
    /* X자 */
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) {
            sum = 0;
            for(int h = 0; h <= M; h++){
                if (h == 0) {
                    sum += town[i][j];
                }
                else {
                    if(i - h >= 0) {
                        if(j - h >= 0) {
                            sum += town[i - h][j - h];
                        }
                        if(j + h < N) {
                            sum += town[i - h][j + h];
                        }
                    }
                    if(i + h < N) {
                        if(j - h >= 0) {
                            sum += town[i + h][j - h];
                        }
                        if(j + h < N) {
                            sum += town[i + h][j + h];
                        }
                    }
                }
            }
            if (sum > maximum) {
                maximum = sum;
            }
            
        }
    }
    
    printf("%d", maximum);
    return 0;
}