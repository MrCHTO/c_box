#include <stdio.h>
int main()
{
    int a;
    scanf("%d", &a);
    if (a % 2 == 0)
    {
        printf("NO");
    }
    else if (a % 3 == 0)
    {
        printf("NO");
    }
    else if (a % 5 == 0)
    {
        printf("NO");
    }
    else if (a % 7 == 0)
    {
        printf("NO");
    }
    else
    {
        printf("YES");
    }

    system("pause");
}