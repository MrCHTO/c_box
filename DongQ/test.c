#include <stdio.h>
int c(int A, int B)
{
    int c;
    c = A + B;
    return c;
}
int main()
{
    int A;
    int B;
    scanf("%d%d", &A, &B);
    printf("%d%d", c(A, B));
}
