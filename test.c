#include <stdio.h>
int main()
{
    int a[10], i, j, temp, flag = 0, k;
    float b, w = 0;
    for (i = 0; i < 10; i++)
    {
        scanf("%d", &a[i]);
    }
    for (i = 0; i < 10; i++)
    {
        w = w + a[i];
    }
    printf("%.3f\n", w);
    b = w / 10;
    printf("%.2f\n", b);

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10 - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    for (i = 0; i < 10; i++)
    {
        k = 0;
        for (j = 0; j < 10; j++)
        {
            if (a[i] == a[j])
            {
                k++;
            }
        }
        if (k > flag)
        {
            flag = k;
            temp = a[i];
        }
    }

    printf("%d\n", temp);

    for (i = 0; i < 10; i++)
    {
        printf("%d ", a[i]);
    }
    system("pause");
}