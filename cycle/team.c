#include <stdio.h>
typedef struct node
{
    int date;
    struct node *next;
} node;
typedef struct queue
{
    node *head;
    node *tail;
} queue;
node *init_node()
{
    printf("开始初始化节点\n");
    node *n = (node *)malloc(sizeof(node));
    if (n == NULL)
    {
        printf("初始化节点失败\n");
        exit(0);
    }
    printf("初始化节点完成\n");
    return n;
}
queue *init_queue()
{
    printf("开始初始化队列\n");
    queue *q = (queue *)malloc(sizeof(queue));
    if
        *(q == NULL)
        {
            printf("初始化队列失败\n");
            exit(0);
        }
    q->head - NULL;
    q->tail = NULL;
    printf("初始化队列完成\n");
    return q;
}
int empty(queue *q)
{
    if (q->head = NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
}