// ���̵� ���� : 0.1 / 5 //
#include <stdio.h>
#include <windows.h>

int change = 1245;
int main() {
    printf("��ȣ���� �� �� �ٲ� �� ���� �̻����� �׸��� �˴ϱ�? \n ��");
    scanf("%d", &change);
    system("cls");
    sleep(2);
    printf(" \" �� �����̳� �� ��ٸ��ž�? \" \n");
    sleep(2);
    printf(" \" 1�� \" \n");
    sleep(2);
    printf(" \" ������ \" \n");
    sleep(2);
    printf(" \" 5�� \" \n");
    sleep(2);
    printf(" \" ���� �ٺ��� ? �󸶳� ��ٸ��ųı� ! \" \n");
    sleep(2);
    printf(" \" ��ȣ���� %d�� �ٲ𵿾� ...... \" \n\n", change);
    sleep(2);
    if(change < 15) printf("hi");
    if(change == 0) {
        printf("\n ���! ��ȣ���� %d�� �ٲ𵿾� ��ٸ��ٸ� ...... \n %d�� ���� ��ٸ��� �˴ϴ�! \n", change, change*200);
    }
    if(0 < change, change < 15) {
        printf("\n ���! ��ȣ���� %d�� �ٲ𵿾� ��ٸ��ٸ� ...... \n %d�� %d�� ���� ��ٸ��� �˴ϴ�! \n", change, (change*200/60), change*200&60);
    } 
    if(18 < change, change < 432) {
        printf("\n ���! ��ȣ���� %d�� �ٲ𵿾� ��ٸ��ٸ� ...... \n %d�ð� %d�� %d�� ���� ��ٸ��� �˴ϴ�! \n", change,  (change*200/60/60), change*200/60&60, change*200&60);
    }
    if(change >= 432) {
        printf("\n ���! ��ȣ���� %d�� �ٲ𵿾� ��ٸ��ٸ� ...... \n %d�� %d�ð� %d�� %d�� ���� ��ٸ��� �˴ϴ�! \n", change,  (change*200/3600/24), change*200/3600&24, change*200/60&60, change*200&60);
    }
    sleep(2);
    sleep(1);
    return 0;
}