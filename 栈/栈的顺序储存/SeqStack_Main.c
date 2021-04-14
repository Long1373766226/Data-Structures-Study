/*************************************************************************
    > File Name: SeqStack_Main.c
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
#include "SeqStack.h"

typedef struct PERSON
{
    char name[64];
    int age;
}Person;


int main(int argc, const char* argv[])
{
    //创建栈
    SeqStack* stack = Init_SeqStack();
    
    //创建数据
    Person p1 = {"aaa",10};
    Person p2 = {"bbb",20};
    Person p3 = {"ccc",30};
    Person p4 = {"ddd",40};
    Person p5 = {"eee",50};

    //入栈
    Push_SeqStack(stack,&p1);
    Push_SeqStack(stack,&p2);
    Push_SeqStack(stack,&p3);
    Push_SeqStack(stack,&p4);
    Push_SeqStack(stack,&p5);

    //输出
    while (Size_SeqStack(stack) > 0)
    {
        //访问栈顶元素
        Person* person =  (Person*)Top_SeqStack(stack);
        printf("Name: %s  Age: %d\r\n",person->name,person->age);

        //弹出栈顶元素
        Pop_SeqStack(stack);
    }
    
    //释放内存
    FreeSpace_SeqStack(stack);

	return 0;
}