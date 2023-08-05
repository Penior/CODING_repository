#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("입력할 숫자의 개수를 입력하세요: ");
    scanf("%d", &n);

    int* list = (int*)malloc(n * sizeof(int)); // 사용자가 입력한 개수만큼 메모리 할당

    printf("정수들을 공백을 포함하여 입력하세요: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &list[i]); // 숫자를 배열에 저장
    }

    // 결과 출력
    printf("입력한 숫자들을 배열에 저장했습니다:\n");
    for (int i = 0; i < n; i++) {
        printf("list[%d] = %d\n", i, list[i]);
    }

    // 동적 메모리 해제
    free(list);

    return 0;
}
