#include <stdio.h>

int main() {
    char str[100];
    printf("문자열을 입력하세요: ");
    scanf("%s", str);
    getchar(); // 개행 문자 소비
    printf("입력한 문자열: %s\n", str);
    return 0;
}
