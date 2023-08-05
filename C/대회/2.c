#include <stdio.h>
#include <math.h>

int K, X, divide, min;
int count, sum, digit = 0;

int main () {
    scanf("%d", &K);
    char X0[K];
    scanf("%s", &X0);
    
    /* 이진법에서 1 위치에 따라 점수 부여 */
    for (int i = 0; i < K; i++) {
        if(X0[K - i - 1] == '1') {
            if((K - i - 1) > digit) {
                digit = (K - i); 
                break;
            }
        }
    }

    min = count + digit;
    
    while (X0 != '{1}') {
        digit = 0;

        X0[K-1] += 1;

        /* 이진법에서 1 더하기 */
        for (int i = 0; i < K; i++) {
            if(X0[K - i - 1] == '2') {
                X0[K - i - 1] = '0';
                X0[K - i - 2] += 1;
            if (X0[0] == '2') {
                X0[K+1] = '0';
                X0[0] = '1';
                }
            }
            if (X0[K - i - 2] == '1') {
                break;
            }
        }

        /* 이진법에서 1 위치에 따라 점수 부여 */
        for (int i = 0; i < K; i++) {
            if(X0[K - i - 1] == '1') {
                if((K - i - 1) > digit) {
                    digit = (K - i); 
                    break;
                }
            }
        }

        count += 1;

        if(count > min) {
            break;
        }

        sum += 1;

        if(count + digit < min) {
            min = count + digit;
        }

    }  
    
    printf("%d", min);
}