#include <stdio.h>
#include <stdlib.h>
//节点申明
typedef struct node
{
    int data;
    struct node *next;
} Lnode, *PLnode;
//定义头指针
PLnode H;
//创建头节点
PLnode Create_LinkList(void)
{
    PLnode H;
    H = (PLnode)malloc(sizeof(Lnode));
    if (H == 1)
    {
        H->next = NULL;
    }
    return H;
}