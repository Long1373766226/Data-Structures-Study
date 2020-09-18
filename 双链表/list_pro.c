/*************************************************************************
    > File Name: list_pro.c
    > Author: 郭耀龙
    > Mail: 1373766226@qq.com 
    > Created Time: Fri 18 Sep 2020 06:12:32 PM CST
    > Function: 
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>

int len;

typedef int Elemtype;   //定义数据类型

/*  定义双向链表的节点  */
typedef struct Node
{
    Elemtype data;
    struct Node *pre;
    struct Node *next;
}Node;

/*  定义双向链表的节点  */
Node *Create_Node(void)
{
    Node *p;
    p = (Node *)malloc(sizeof(Node));
    if(p == NULL)
    {
        printf("动态内存分配失败\n");
        exit(0);
    }
    scanf("%d",&(p->data)); //创建链表节点的数据
    p->pre = NULL;
    p->next = NULL;
    return (p);
}

/*  建立含有N个结点的双向链表   */
Node *Create_List(int n)
{
    Node *head; //头结点
    Node *p;    //尾结点
    Node *s;    //新结点
    
    int i;
    if(n >= 1)    //结点的个数 >= 1的时候，先生成第一个结点
    {
        s = Create_Node();
        head = s;
        p = s;
    }
    for(i = 2;i<=n;i++)
    {
        s = Create_Node();
        p->next = s;
        s->pre = p;
        p = s;
    }
    len = n;
    if(n>=1)
        return (head);
    else
        return 0;
}

/*  链表的长度  */
int Len_List(int len)
{
    return len;
}

/*  定位到链表的任意位置  */
Node *Pos_List(Node *head, int n)
{
    int i=1;
    Node *p;
    if(i <= n)
    {
        p = head;
        for (i = 2; i <= n; i++)
            p = p->next;
    }
    return p;
}

/*  正向遍历一个链表  */
void Out_Front_List(Node *head)
{
    if(head == NULL)
        printf("输入的链表有误，链表不存在");
    Node *p;
    p = head;
    while (p)
    {
        printf("%d ",p->data);
        p = p->next;
    }
}

/*  反向遍历一个链表  */
void Out_Reverse_List(Node *head)
{
    if(head == NULL)
        printf("输入的链表有误，链表不存在");
    int n;
    n = Len_List(len);
    Node *p;
    p = Pos_List(head,n);
    while (p)
    {
        printf("%d ",p->data);
        p = p->pre;
    }
}

/*  插入结点——头插法  */
Node *Insert_List_Head(Node *head)
{
    Node *p;
    p = Create_Node();
    p->next = head;
    head->pre = p;
    head = p;
    len++;
    return p;
}

/*  插入结点——尾插法  */
Node *Insert_List_Tail(Node *head)
{
    int n;
    n = Len_List(len);
    Node *p, *s;
    s = Create_Node();
    s = Pos_List(head,n);
    p->next = s;
    s->pre = p;
    len++;
    return head;
}

/*  插到任意位置之前  */
Node *Insert_Before_List(Node *head)
{
    int n,data,pos_n;
    Node *s, *p;
    printf("请输入要插入结点的位置：");
    scanf("%d", &n);
    printf("请输入要插入的节点的值：");
    scanf("%d", &data);
    pos_n = Len_List(len);
    if(n > pos_n) //如果输入的位置 > 链表总长度，则指向尾结点
        head = Insert_List_Tail(head);
    else if(n <= 1)
        head = Insert_List_Head(head);
    else
    {
        s = Pos_List(head, n);
        p = Create_Node();
        s->pre->next = p;
        p->pre = s->pre;
        p->next = s;
        s->pre = p;
    }
    len++;
    return head;
}

/*  插到任意位置之后  */
Node *Insert_After_List(Node *head)
{
    int n,data,pos_n;
    Node *s, *p;
    printf("请输入要插入结点的位置：");
    scanf("%d", &n);
    printf("请输入要插入的节点的值：");
    scanf("%d", &data);
    pos_n = Len_List(len);
    if(n >= pos_n) //如果输入的位置 > 链表总长度，则指向尾结点
        head = Insert_List_Tail(head);
    else if(n < 1)
        head = Insert_List_Head(head);
    else
    {
        s = Pos_List(head, n);
        p = Create_Node();
        p->next = s->next;
        s->next->pre = p;
        s->next = p;
        p->pre = s;
    }
    len++;
    return head;
}

/*  删除头结点  */
Node *Delete_Start_List(Node *head)
{
    Node *p;
    p = head;
    head = head->next;
    head->pre = NULL;
    free(p);
    len--;
    return head;
}

/*  删除尾结点  */
Node *Delete_End_List(Node *head)
{
    Node *p, *s;
    int n;
    n = Len_List(len);
    s = Pos_List(head, n);
    p = s;
    p = p->pre;
    p->next = NULL;
    free(s);
    len--;
    return head;
}

/*  删除指定位置的节点  */
Node *Delete_List(Node *head)
{
    int n,i;
    Node *p;
    n = Len_List(len);
    printf("请输入要删除结点的位置: ");
    scanf("%d",&i);
    if(i <= 1)
        head = Delete_Start_List(head);
    else if(i>n)
        head = Delete_End_List(head);
    else
    {
        p = Pos_List(head,i);
        p->pre->next = p->next;
        p->next->pre = p->pre;
        free(p);
    }
    len--;
    return head;
}

/***********************************************
 * 函数声明
***********************************************/

Node *Create_Node(void);                // 定义双向链表的节点
Node *Create_List(int n);                // 建立含有N个结点的双向链表
int Len_List(int len);                  //链表的长度
Node *Pos_List(Node *head, int n);      //定位到链表的任意位置 
void Out_Front_List(Node *head);        //正向遍历一个链表
void Out_Reverse_List(Node *head);      //反向遍历一个链表
Node *Insert_List_Head(Node *head);     //插入结点——头插法
Node *Insert_List_Tail(Node *head);     //插入结点——尾插法
Node *Insert_Before_List(Node *head);   //插到任意位置之前
Node *Insert_After_List(Node *head);    //插到任意位置之后
Node *Delete_Start_List(Node *head);    //删除头结点
Node *Delete_End_List(Node *head);      //删除尾结点
Node *Delete_List(Node *head);          //删除指定位置的节点


int main(int argc, const char* argv[])
{
    Node *head;

    printf("请输入要建立双向链表的长度：");
    scanf("%d",&len);
    printf("请为双向链表赋值：");
    head = Create_List(len);
    printf("链表的长度为：%d\n",len = Len_List(len));

    printf("正向遍历双向链表：");
    Out_Front_List(head);
    printf("\n链表的长度为：%d\n",len = Len_List(len));
    
    printf("\n反向遍历双向链表：");
    Out_Reverse_List(head);
    printf("\n链表的长度为：%d\n",len = Len_List(len));

    





	return 0;
}
