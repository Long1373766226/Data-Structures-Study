/*************************************************************************
    > File Name: List.c
    > Author: 郭耀龙
    > Mail: 1373766226@qq.com 
    > Created Time: Fri 18 Sep 2020 04:12:36 PM CST
    > Function: 双向链表的学习
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>

typedef int Elemtype;

typedef struct Node
{
    Elemtype data;
    struct Node *prev, *next;
}pNode;

/*  初始化链表，尾插法*/
pNode *InitList(pNode **head, int n)
{
    pNode *p, *s;
    (*head) = (pNode *)malloc(sizeof(pNode));
    if((*head) == NULL)
    {
        printf("Apply the place Failure!\n");
        exit(0);
    }
    (*head)->next = NULL;   //head的prev和next均指向NULL
    (*head)->prev = NULL;
    p = (*head);    //p指向head
    int i;
    for(i=0; i<n; ++i)
    {
        s = (pNode *)malloc(sizeof(pNode));
        if(s == NULL)
        {
            printf("Apply the place Failure!\n");
        
            exit(0);
        }
        printf("Input the value of the %dth node:",i+1);
        scanf("%d", &s->data);
        s->next = NULL;
        p->next = s;
        s->prev = p;
        p = s;      //p指向尾结点
    }
    return p;
}

/*  遍历打印结点  */
void PrintList(pNode *head)
{
    pNode *p;
    p = head->next;
    if(head->next == NULL)
    {
        printf("The List is Empty!\n");
        exit(0);
    }
    printf("The List is :");
    while (p)
    {
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}

/*  清空链表  */
void DeleteList(pNode **head)
{
    pNode *p;
    while ((*head)->next != NULL)
    {
        p = (*head);
        p->next->prev = NULL;   
        (*head) = p->next;
        free(p);
    }
}

/*  查找链表内的某个值  */
int SearchList(pNode *head)
{
    int num,i;
    printf("Values are about to be finded:");
    scanf("%d", &num);
    pNode *p;
    p = head->next;
    while (p)
    {
        ++i;
        if(p->data == num)
        {
            printf("The data %d Node is: %d\n",num,i);
            return num;
        }
        p = p->next;
    }
    return 0;
}

/*  删除链表中某个元素  */
/*  令p的前驱节点和后驱结点互相指向即可，如果P是尾结点，则直接让前驱结点的next指向NULL*/
void DelNumqList(pNode **head, int n)
{
    int i;
    pNode *p;
    p = (*head)->next;
    for(i=1; i<n; ++i)
        p = p->next;
    if(p->next == NULL)
    {
        p->prev->next = NULL;
        free(p);
    }
    else
    {
        p->next->prev = p->prev;   
        p->prev->next = p->next;
        free(p);
    }
}

int main(int argc, const char* argv[])
{
    int n,element;
    pNode *head, *last;
    /*******************************************************/
    printf("Please input the size of the list:");
    scanf("%d", &n);
    last = InitList(&head,n);
    printf("%d %d \n", head->next->data, last->data); //打印为第一个和最后一个的元素
    PrintList(head);
    /*******************************************************/
    element = SearchList(head); //搜索某个值并删除结点
    if(element>0 && element <=n)
    {
        DelNumqList(&head,element);
        PrintList(head);
    }
    else
        printf("Element does not exist, cannot be deleted\n");
    /*******************************************************/
    DeleteList(&head);
    PrintList(head);

	return 0;
}
