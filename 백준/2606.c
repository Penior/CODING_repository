#include <stdio.h>
#include <malloc.h>

int *Start, *End;

int main()
{
    int ComN;
    int LineN;
    int count = 1;

    scanf("%d", &ComN);
    scanf("%d", &LineN);

    int *List = (int *)malloc(LineN * sizeof(int));
    List[0] = 1;

    Start = (int *)malloc(LineN * sizeof(int));
    End = (int *)malloc(LineN * sizeof(int));

    for (int i = 0; i < LineN; i++)
    {
        scanf("%d %d", &Start[i], &End[i]);
    }

    for (int i = 0; i < count; i++) {
        // Start List 같은 지 확인 //
        for (int h = 0; h < LineN; h++) {
            if(List[i] == Start[h]) {
                List[count] = End[h];
                count += 1;
                for(int k = 0; k < count - 1; k++) {
                    if(End[h] == List[k]) {
                        count -= 1;
                        List[count] = 0;
                        break;
                    }
                }
            }

        // End List 같은 지 확인 //
            if(List[i] == End[h]) {
                List[count] = Start[h];
                count += 1;
                for(int k = 0; k < count - 1; k++) {
                    if(Start[h] == List[k]) {
                        count -= 1;
                        List[count] = 0;
                        break;
                    }
                }
            }

        }
    }

    printf("%d", count - 1);
    
    free(List);
    free(Start);
    free(End);

    return 0;
}
