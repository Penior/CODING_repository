#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[100];
    int list[100]; // 최대 100개의 숫자 저장 가능

    printf("정수들을 공백을 포함하여 입력하세요: ");
    fgets(input, sizeof(input), stdin); // fgets로 입력 받음

    int count = 0;
    char *token = strtok(input, " \n"); // 공백과 줄바꿈을 기준으로 문자열 분리

    while (token != NULL) {
        list[count] = atoi(token); // 정수로 변환하여 배열에 저장
        count++;
        token = strtok(NULL, " \n"); // 다음 문자열로 이동
    }

    // 결과 출력
    printf("입력한 숫자들을 배열에 저장했습니다:\n");
    for (int i = 0; i < count; i++) {
        printf("list[%d] = %d\n", i, list[i]);
    }

    return 0;
}