/*************************************************************************
    > File Name: stack.c
    > Author: 郭耀龙
    > Mail: 1373766226@qq.com 
    > Created Time: Wed 14 Apr 2021 10:59:02 PM CST
    > Function: 
        栈的顺序储存
        先进后出，只能从栈顶进入
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include "LinkStack.h"


//初始化栈
LinkStack* Init_LinkStack(){
    LinkStack* stack = (LinkStack*)malloc(sizeof(LinkStack));
    
    stack->head.next = NULL;
    stack->size = 0;
    
    return stack;
}

//入栈
void Push_LinkStack(LinkStack* stack, LinkNode* data){
    if(stack == NULL || data == NULL){
        return;
    }
    
    data->next = stack->head.next;
    stack->head.next = data;
    stack->size++;
}

//返回栈顶元素
void* Top_LinkStack(LinkStack* stack){
    if(stack->size == 0 || stack == NULL){
        return NULL;
    }
    return stack->head.next;
}

//出栈
void Pop_LinkStack(LinkStack* stack){
    if(stack->size == 0 || stack == NULL){
        return;
    }
    //第一个有效结点
    LinkNode* pNext = stack->head.next;
    //指向第二个，将第一个原来的Node丢弃
    stack->head.next = pNext->next;
    stack->size--;
}

//返回栈中元素的个数
int Size_LinkStack(LinkStack* stack){
    if(stack == NULL) return -1;
    return stack->size;
}

//清空栈
void Clear_LinkStack(LinkStack* stack){
    if(stack == NULL)return;
    stack->head.next = NULL;
    stack->size = 0;
}

//销毁
void FreeSpace_LinkStack(LinkStack* stack){
    if(stack == NULL)return;
    free(stack);
}
