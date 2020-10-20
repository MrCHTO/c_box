#include <stdio.h>
#include <stdlib.h>
int num = 0;
typedef struct LinkList
{
    int data;
    struct LL *next;
} LL;
LL *init_LL()
{
    LL *n = (LL *)malloc(sizeof(LL));
    if (n == NULL)
    {
        exit(0);
    }
    return n;
}
LL *creat_LL(int n)
{
    LL *phead, *pend, *pnew;
    phead = init_LL();
    pend = phead; //头尾指针指向一处
    for (int i = 0; i < n; i++)
    {
        pnew = init_LL();
        printf("please input data:");
        scanf("%d", &pnew->data);
        pend->next = pnew;
        pend = pnew;
        num++;
    }
    pend->next = NULL;
    return phead;
}
int main()
{
    LL *L1, *pmov;
    int n;
    printf("please input number:");
    scanf("%d", &n);
    L1 = creat_LL(n);
    pmov = L1;
    while (pmov->next != NULL)
    {
        pmov = pmov->next;
        printf("%d ", pmov->data);
    }
    system("pause");
}