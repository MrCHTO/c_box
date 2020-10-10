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
queue *init_queue()
{
    printf("��ʼ��ʼ������...----------");
    queue *q = (queue *)malloc(sizeof(queue));
    if (q == NULL)
    {
        printf("��ʼ������ʧ��\n");
        exit(0);
    }
    q->head = NULL;
    q->tail = NULL;
    printf("��ʼ���������\n");
    return q;
}
int empty(queue *q)
{
    if (q->head == NULL)
    {
        printf("����Ϊ�գ�\n");
        return 1;
    }
    else
    {
        printf("���в�Ϊ�գ�\n");
        return 0;
    }
}
void push(queue *q)
{
    int data;
    node *n = init_node();
    printf("������ýڵ�data��");
    scanf("%d", &data);
    n->date = data;
    n->next = NULL;
    if (empty(q))
    {
        q->head = n;
        q->tail = n;
        printf("ͷ�ڵ����ɹ���\n");
    }
    else
    {
        q->tail->next = n;
        q->tail = n;
        printf("�ڵ����ɹ���\n");
    }
}
void pop(queue *q)
{
    node *n = q->head;
    printf("�ýڵ�dataΪ��%d \n", n->date);
    if (empty(q))
    {
        printf("���п��ˣ�\n");
        return;
    }
    if (q->head == q->tail)
    {
        q->head = NULL;
        q->tail = NULL;
        free(n);
        printf("�ڵ��ͷ���Ϊ�գ�\n");
    }
    else
    {
        q->head = q->head->next;
        free(n);
        printf("�ڵ㱻�ͷţ�\n");
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