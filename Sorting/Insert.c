#include <stdio.h>
int number[100];
int len;
int main()
{
    int i, temp, j;
    printf("please input the len:\n");
    scanf("%d", &len);
    printf("please input the number:\n");
    for (i = 0; i < len; i++)
    {
        scanf("%d", &number[i]);
    }
    for (i = 1; i < len; i++)
    {
        temp = number[i];
        j = i - 1;
        while (j >= 0 && number[j] > temp)
        {
            number[j + 1] = number[j];
            j--;
        }
        number[j + 1] = temp;
    }
    for (i = 0; i < len; i++)
    {
        printf("%d ", number[i]);
    }
    getchar();
    system("pause");
}