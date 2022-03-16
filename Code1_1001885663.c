#include <stdio.h>

int main()
{
    int i_e, j_e, k_e, i_s, j_s, k_s;
    printf("Enter i's starting value ");
    scanf("%d", &i_s);
    printf("Enter i's ending value ");
    scanf("%d", &i_e);
    printf("Enter j's starting value ");
    scanf("%d", &j_s);
    printf("Enter j's ending value ");
    scanf("%d", &j_e);
    printf("Enter k's starting value ");
    scanf("%d", &k_s);
    printf("Enter k's ending value ");
    scanf("%d", &k_e);
    printf("\n\n");

    for(int i = i_s; i<i_e; i++)
    {
        for(int j = j_s; j<j_e; j++)
        {
            for(int k = k_s; k<k_e; k++)
            {
                printf("*");
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}