#include <stdio.h>
int number[100];
int len = 0;
void quick(int left, int right)
{
    int pleft, pright;
    int temp, mid;
    if (left > right)
    {
        return;
    }
    mid = number[left];
    pleft = left;
    pright = right;
    while (pleft != pright)
    {
        while (number[pright] >= mid && pleft < pright)
        {
            pright--;
        }
        while (number[pleft] <= mid && pleft < pright)
        {
            pleft++;
        }
        temp = number[pleft];
        number[pleft] = number[pright];
        number[pright] = temp;
    }
    number[left] = number[pleft];
    number[pleft] = mid;
    quick(left, pleft - 1);
    quick(pleft + 1, right);
}
int main()
{
    int i;
    printf("please input the len:\n");
    scanf("%d", &len);
    printf("please input the number:\n");
    for (i = 0; i < len; i++)
    {
        scanf("%d", &number[i]);
    }
    quick(0, len - 1);
    for (i = 0; i < len; i++)
    {
        printf("%d ", number[i]);
    }
    getchar();
    system("pause");
}