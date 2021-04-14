/*************************************************************************
    > File Name: LinkStack_Main.c
    > Author: 郭耀龙
    > Mail: 1373766226@qq.com 
    > Created Time: Wed 14 Apr 2021 11:21:26 PM CST
    > Function: 测试栈的顺序储存
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include "LinkStack.h"

typedef struct PERSON{
    LinkNode node;
    char name[64];
    int age;
}Person;


int main(int argc, const char* argv[])
{
    //创建栈
    LinkStack* stack = Init_LinkStack();
    
    //创建数据
    Person p1,p2,p3,p4,p5;
    strcpy(p1.name, "aaa");
    strcpy(p2.name, "bbb");
    strcpy(p3.name, "ccc");
    strcpy(p4.name, "ddd");
    strcpy(p5.name, "eee");

    p1.age = 10;
    p2.age = 20;
    p3.age = 30;
    p4.age = 40;
    p5.age = 50;

    //入栈
    Push_LinkStack(stack,&p1);
    Push_LinkStack(stack,&p2);
    Push_LinkStack(stack,&p3);
    Push_LinkStack(stack,&p4);
    Push_LinkStack(stack,&p5);

    //输出
    while (Size_LinkStack(stack) > 0)
    {
        //取出栈顶元素
        Person* person =  (Person*)Top_LinkStack(stack);
        printf("Name: %s  Age: %d\r\n",person->name,person->age);

        //弹出栈顶元素
        Pop_LinkStack(stack);
    }
    
    //释放内存
    FreeSpace_LinkStack(stack);

	return 0;
}