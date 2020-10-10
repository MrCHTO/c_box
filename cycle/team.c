#include <stdio.h>
#include <stdlib.h>
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
queue *init_queue()
{
    printf("开始初始化队列...----------");
    queue *q = (queue *)malloc(sizeof(queue));
    if (q == NULL)
    {
        printf("初始化队列失败\n");
        exit(0);
    }
    q->head = NULL;
    q->tail = NULL;
    printf("初始化队列完成\n");
    return q;
}
int empty(queue *q)
{
    if (q->head == NULL)
    {
        printf("队列为空！\n");
        return 1;
    }
    else
    {
        printf("队列不为空！\n");
        return 0;
    }
}
void push(queue *q)
{
    int data;
    node *n = init_node();
    printf("请输入该节点data：");
    scanf("%d", &data);
    n->date = data;
    n->next = NULL;
    if (empty(q))
    {
        q->head = n;
        q->tail = n;
        printf("头节点加入成功！\n");
    }
    else
    {
        q->tail->next = n;
        q->tail = n;
        printf("节点加入成功！\n");
    }
}
void pop(queue *q)
{
    node *n = q->head;
    printf("该节点data为：%d \n", n->date);
    if (empty(q))
    {
        printf("队列空了！\n");
        return;
    }
    if (q->head == q->tail)
    {
        q->head = NULL;
        q->tail = NULL;
        free(n);
        printf("节点释放且为空！\n");
    }
    else
    {
        q->head = q->head->next;
        free(n);
        printf("节点被释放！\n");
    }
}
int main()
{
    queue *q;
    q = init_queue();
    for (int i = 0; i < 10; i++)
    {
        push(q);
    }
    printf("\n");
    for (int i = 0; i < 10; i++)
    {
        pop(q);
    }
    system("pause");
}