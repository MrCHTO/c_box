#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int date;
    struct node *next;
} node;
node *init_node()
{
    printf("��ʼ��ʼ���ڵ�...----------");
    node *n = (node *)malloc(sizeof(node));
    if (n == NULL)
    {
        printf("��ʼ���ڵ�ʧ��\n");
        exit(0);
    }
    printf("��ʼ���ڵ����\n");
    return n;
}
int empty(node *phead)
{
    if (phead == NULL)
    {
        printf("����Ϊ�գ�\n");
        return 1;
    }
    else
    {
        printf("����Ϊ�գ�\n");
        return 0;
    }
}
node *creat_LinkList(int n)
{
    node *phead, *pend;
    phead = init_node();
    pend = init_node();
    printf("\n");
    phead = NULL;
    pend = NULL;
    for (int i = 0; i < n; i++)
    {
        node *n = init_node();
        printf("������ýڵ�data��");
        scanf("%d", &n->date);
        n->next = NULL;
        if (empty(phead))
        {
            phead = n;
            pend = n;
            printf("ͷ�ڵ����ɹ���\n");
        }
        else
        {
            pend->next = n;
            pend = n;
            printf("�ڵ����ɹ���\n");
        }
        printf("\n");
    }
    return phead;
}
int main()
{
    node *LinkList, *pmov;
    int number;
    printf("please input number:");
    scanf("%d", &number);
    pmov = LinkList = creat_LinkList(number);
    while (pmov != NULL)
    {
        printf("%d ", pmov->date);
        pmov = pmov->next;
    }
    system("pause");
}