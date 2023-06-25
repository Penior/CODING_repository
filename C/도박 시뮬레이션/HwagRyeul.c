#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int main()
{
    double percen = 0;
    int random = 0;
    double reward = 0;
    double success = 0;
    double PerPer = 0; // 기준 퍼센트 //
    printf("전체 금액에서 베팅할 비율을 거실 지 골라주세요 (0 < x < 1, 소수 다섯 번째 자리까지만)\n");
    scanf("%f", &percen);
    printf("배율을 적어주세요. (n배를 적을 시, 확률이 맞을 경우 n배 이득입니다. 소수 다섯 번째 자리까지만\n");
    scanf("%f", &reward);
    printf("성공 확률을 적어주세요. (0 < x < 1, 소수 다섯 번째 자리까지만)\n");
    scanf("%f", &PerPer);
    PerPer = PerPer + 100;
    printf("%d",PerPer);
    success = PerPer;
    sleep(3);
    srand(time(NULL));
    double sum = 0;
    system("cls");
    for(int j=0;j<100;j++) {
        double money = 100.0;
        for(int i=0;i<100;i++) {
        random = rand()%1000000 + 1;
        if(random <= PerPer) {
            money = money * (1 + (reward * money * percen));
        }
        else if(PerPer < random && random < 1000000) {
            money = money * (1 - percen);
        }
        }
        printf("%d번째 시도, 총 결과 : %f, 이득 배율 : %f%% \n", j+1, money, money/100);
        sum = sum + money * 10000;
    }
    sum = sum / 100000000;
    printf("평균 비율 : %f %%",sum);
    system("PAUSE");
}