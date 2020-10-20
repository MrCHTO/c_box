#include <stdio.h>
#include <stdlib.h>
int num = 0;
typedef struct node
{
    int data;
    struct node *next;
} node;
typedef struct lb
{
    node *head;
} lb;
node *init_node()
{
    node *n = (node *)malloc(sizeof(node));
    if (n == NULL)
    {
        exit(0);
    }
    return n;
}
lb *init_lb()
{
    lb *l = (lb *)malloc(sizeof(lb));
    if (l == NULL)
    {
        exit(0);
    }
    l->head = NULL;
    return l;
}
int empty(lb *l)
{
    if (l->head == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(lb *l)
{
    int data;
    node *n = init_node();
    num++;
    printf("please input data:");
    scanf("%d", &data);
    printf("this node add is:%p\n", n);
    n->data = data;
    n->next = NULL;
    if (empty(l))
    {
        l->head = n;
    }
    else
    {
        
        l->head->next = n;
        l->head = n;
    }
}
void pf(lb *l)
{
    int j = 1;
    node *mov = l->head;
    printf("%d node add is:%p\n", j, mov);
    printf("%d\n", mov->data);
    while (mov != NULL)
    {
        mov = mov->next;
        j++;
        printf("%d node add is:%p\n", j, mov);
        printf("%d\n", mov->data);
    }
}
int main()
{
    int n;
    lb *l;
    l = init_lb();
    printf("please input number:");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        push(l);
    }
    pf(l);
    system("pause");
}