#include <stdio.h>
int main()
{
    int a[5], s = 0, i;
    for (i = 0; i < 5; i++)
    {
        scanf("%d", &a[i]);
        s = s + a[i];
    }
    printf("%d", s);
    system("pause");
}