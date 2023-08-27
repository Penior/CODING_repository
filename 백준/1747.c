#include <stdio.h>
#include <math.h>

int palindrome(int n) {
    int original = n;
    int reversed = 0;
    while (n > 0) {
        int digit = n % 10;
        reversed = reversed * 10 + digit;
        n /= 10;
    }
    return original == reversed;
}

int prime(int N) {

    if (N == 1) {
        return 0;
    }

    for (int i = 2; i * i <= N; i++) {
        if(N % i == 0) {
            return 0;
            break;
        }
    }
    return 1;
}

int main() {

    int N;
    scanf("%d", &N);

    while (1) {

        if (palindrome(N) && prime(N)) {
            printf("%d", N);
            break;
        }

        N += 1;
    }


}