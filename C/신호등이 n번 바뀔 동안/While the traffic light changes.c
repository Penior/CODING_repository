// 난이도 예상 : 0.1 / 5 //
#include <stdio.h>
#include <windows.h>

int change = 1245;
int main() {
    printf("신호등이 몇 번 바뀔 때 가장 이상적인 그림이 됩니까? \n ㄴ");
    scanf("%d", &change);
    system("cls");
    sleep(2);
    printf(" \" 얼마 동안이나 나 기다린거야? \" \n");
    sleep(2);
    printf(" \" 1분 \" \n");
    sleep(2);
    printf(" \" 거짓말 \" \n");
    sleep(2);
    printf(" \" 5분 \" \n");
    sleep(2);
    printf(" \" 내가 바보냐 ? 얼마나 기다린거냐구 ! \" \n");
    sleep(2);
    printf(" \" 신호등이 %d번 바뀔동안 ...... \" \n\n", change);
    sleep(2);
    if(change == 0) {
        printf("\n 잠깐! 신호등이 %d번 바뀔동안 기다린다면 ...... \n %d초 동안 기다리게 됩니다! \n", change, change*200);
    }
    if(0 < change && change < 18) {
        printf("\n 잠깐! 신호등이 %d번 바뀔동안 기다린다면 ...... \n %d분 %d초 동안 기다리게 됩니다! \n", change, (change*200)/60, (change*200)%60);
    } 
    if(18 <= change && change < 432) {
        printf("\n 잠깐! 신호등이 %d번 바뀔동안 기다린다면 ...... \n %d시간 %d분 %d초 동안 기다리게 됩니다! \n", change,  (change*200/60/60), change*200/60%60, change*200%60);
    }
    if(change >= 432) {
        printf("\n 잠깐! 신호등이 %d번 바뀔동안 기다린다면 ...... \n %d일 %d시간 %d분 %d초 동안 기다리게 됩니다! \n", change,  ((change*200)/3600)/24, ((change*200)/3600)%24, change*200/60%60, change*200%60);
    }
    system("PAUSE");
    return 0;
}