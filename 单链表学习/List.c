/*************************************************************************
    > File Name: List.c
    > Author: 郭耀龙
    > Mail: 1373766226@qq.com 
    > Created Time: Wed 16 Sep 2020 11:21:44 PM CST
    > Function: 单链表学习
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>

typedef int  ElemType;
typedef struct Node     //用结构体定义结点
{
    ElemType data;
    struct Node *next;
} Node, *LinkList;

//初始化一个结点
void InitLinkedList()   
{
    Node *L;                            //定义一个新结点
    L = (Node *)malloc(sizeof(Node));   //头结点申请地址
    if(L == NULL)
        printf("Failed to apply for space!\n");
    L->next = NULL;
}

//头插法
LinkList CreatLinkListHead(int n)
{
    int i;  //计数用
    int x;  //存储数据
    Node *L;                            //定义寻找整个链表的头结点
    L = (Node *)malloc(sizeof(Node));   //申请头结点的地址
    L->next = NULL;                     //头结点的后继指针为空
    printf("Please Input Integer: ");
    for(i=0; i<n; i++)
    {
        Node *p;
        p = (Node *)malloc(sizeof(Node));
        scanf("%d",&x);             //输入存取的数据
        p->data = x;                //将数据存入p新结点
        p->next = L->next;          //将新结点的后继结点指向头结点
        L->next = p;                //将头指针的后继结点指向新插入的结点
        /*  1. L->next  ->  NULL               */
        /*  2. p->next  ->  NULL               */
        /*  3. L->next  ->  p->next ->  NULL   */
    }
    return L;       //返回整个链表的头结点即整个链表
}

//尾插法
LinkList CreatLinkListTail(int n)
{
    int x;
    Node *L;                 //定义寻找整个链表的头结点
    Node *r;                 //定义整个链表的尾结点
    L = (Node *)malloc(sizeof(Node));
    L->next = NULL;
    r = L;                   //此时无结点，头结点即尾结点
    printf("Please Input Integer: ");
    while (n--)
    {
        scanf("%d",&x);
        Node *p;        //定义一个新结点
        p = (Node *)malloc(sizeof(Node));
        p->data = x;
        r->next = p;            //尾结点指向新结点
        r = p;                  //将当前的新结点定义为表尾终端结点
    }
    r->next = NULL;
    return L;
}

//插入元素
void InsertLinkedList(LinkList L, int i, ElemType x)
{
    LinkList p;   //定义一个结点p，目的：一直往后找到第i个元素
    //把链表的头结点赋值给P,保持L头结点不变，相当于你是队伍第一个人
    //另外找了一个人去帮你找队伍的第几个人
    p = L;
    int j = 1;
    while (j<i)
    {
        p = p->next;
        j++;
    }
    Node *s;        //定义插入的结点
    s = (Node *)malloc(sizeof(Node));
    s->data = x;
    s->next = p->next;  //将新结点指向找到的位置结点的后继结点前插入
    p->next = s;        //将位置的结点
    /*  1. L->next   ->  ... ->  p -> p-next -> ... ->  NULL    */
    /*  2. L->next   ->  ... ->  p -> s-next -> p-next -> ... ->  NULL    */  
}

//遍历链表
void TraversingLinkedList(LinkList L)
{
    Node *p;
    printf("LinkedList: ");
    for(p = L->next; p!=NULL; p=p->next)
    {
        printf("%d ",p->data);
    }
}

//删除链表L在i位置上的元素
void deleteLinkedList(LinkList L, int i)
{
    int j = 1;
    LinkList p,q;
    p = L;      //指向头结点
    while (j<i)
    {
        p = p->next;
        j++;
    }
    q = p->next;    //将第i个位置先存在q；
    p->next = q->next;  //直接跳过第i个结点，指向下一个后级元素
    free(q);        //释放掉第i个位置的结点内存
}

//获取链表L在第i个位置的元素
int GetElem(LinkList L, int i)
{
    ElemType e;
    int j = 1;
    LinkList p; 
    p = L->next;        //p指向L的第一个结点
    while (p && j<i)
    {
        p = p->next;
        j++;
    }
    if(!p || j>i)
    {
        printf("The %d position Node doesnot exsit\n", i);
        return -1;
    }
    e = p->data;
    return e;
}

//求单链表的长度
int GetLength(LinkList L)
{
    LinkList p;
    int length = 0;
    p = L->next;
    while (p)
    {
        printf("The LinkedList Data = %d\n",p->data);
        length++;
        p = p->next;
    }

    return length;
}

//清空整个线性表
void ClearLinkedLinst(LinkList L)
{
    LinkList p,q;
    p = L->next;
    while (p)
    {
        q = p->next;  
        free(p);
        p = q;
        /*  1. L -> p -> p-next -> NULL  */
        /*  2. L -> p & q -> p-next -> NULL  */
    }
    L->next = NULL;
}


int main(int argc, const char* argv[])
{
    int n,i,x;
    LinkList H;
    printf("请输入单链表的长度（头插法）：");
    scanf("%d",&n);
    H = CreatLinkListHead(n);   
    TraversingLinkedList(H);    //遍历链表
    printf("\n");

    printf("请输入单链表的长度（尾插法）：");
    scanf("%d",&n);
    H = CreatLinkListTail(n);   
    TraversingLinkedList(H);    //遍历链表
    printf("\n");

    printf("\nLinkedList Length = %d\n\n", GetLength(H));

    printf("请输入要获取元素的位置：");
    scanf("%d", &i);
    printf("The %d position Data = %d\n",i, GetElem(H,i));

    printf("请输入要插入的位置i和元素e:");
    scanf("%d %d", &i, &x);
    InsertLinkedList(H,i,x);
    TraversingLinkedList(H);

    printf("\n请输入要删除的位置i:");
    scanf("%d", &i);
    deleteLinkedList(H,i);
    TraversingLinkedList(H);

    printf("\n是否要整表删除1/0? \n");
    scanf("%d", &x);
    if(x == 1)
    {
        ClearLinkedLinst(H);
        printf("单链表为：");
        TraversingLinkedList(H);
    }
    else
    {
        printf("单链表仍为：");
        TraversingLinkedList(H);
    }
    printf("\n");

	return 0;
}
