#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int date;
    struct node *next;
} node;
node *init_node()
{
    printf("开始初始化节点...----------");
    node *n = (node *)malloc(sizeof(node));
    if (n == NULL)
    {
        printf("初始化节点失败\n");
        exit(0);
    }
    printf("初始化节点完成\n");
    return n;
}
int empty(node *phead)
{
    if (phead == NULL)
    {
        printf("链表为空！\n");
        return 1;
    }
    else
    {
        printf("链表不为空！\n");
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
        printf("请输入该节点data：");
        scanf("%d", &n->date);
        n->next = NULL;
        if (empty(phead))
        {
            phead = n;
            pend = n;
            printf("头节点加入成功！\n");
        }
        else
        {
            pend->next = n;
            pend = n;
            printf("节点加入成功！\n");
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