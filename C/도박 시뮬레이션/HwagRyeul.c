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
    double PerPer = 0; // ���� �ۼ�Ʈ //
    printf("��ü �ݾ׿��� ������ ������ �Ž� �� ����ּ��� (0 < x < 1, �Ҽ� �ټ� ��° �ڸ�������)\n");
    scanf("%f", &percen);
    printf("������ �����ּ���. (n�踦 ���� ��, Ȯ���� ���� ��� n�� �̵��Դϴ�. �Ҽ� �ټ� ��° �ڸ�������\n");
    scanf("%f", &reward);
    printf("���� Ȯ���� �����ּ���. (0 < x < 1, �Ҽ� �ټ� ��° �ڸ�������)\n");
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
        printf("%d��° �õ�, �� ��� : %f, �̵� ���� : %f%% \n", j+1, money, money/100);
        sum = sum + money * 10000;
    }
    sum = sum / 100000000;
    printf("��� ���� : %f %%",sum);
    system("PAUSE");
}