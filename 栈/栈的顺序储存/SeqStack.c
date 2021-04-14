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
#include "SeqStack.h"


//初始化栈
SeqStack* Init_SeqStack(){
    SeqStack* stack = (SeqStack*)malloc(sizeof(SeqStack));
    for(int i = 0; i < MAX_SIZE; i++){
        stack->data[i] = NULL;
    }
    stack->size = 0;
    return stack;
}

//入栈
void Push_SeqStack(SeqStack* stack, void* data){
    if(stack->size == MAX_SIZE || stack == NULL || data == NULL){
        return;
    }
    stack->data[stack->size] = data;
    stack->size++;
}

//返回栈顶元素
void* Top_SeqStack(SeqStack* stack){
    if(stack->size == 0 || stack == NULL){
        return NULL;
    }
    return stack->data[stack->size-1];
}

//出栈
void Pop_SeqStack(SeqStack* stack){
    if(stack->size == 0 || stack == NULL){
        return;
    }
    stack->data[stack->size-1] = NULL;
    stack->size--;
}

//判断是否为空
int IsEmpty(SeqStack* stack){
    if(stack == NULL || stack->size == 0){
        return SEQSTACK_FALSE;
    }
    return SEQSTACK_TRUE;
}

//返回栈中元素的个数
int Size_SeqStack(SeqStack* stack){
    return stack->size;
}

//清空栈
void Clear_SeqStack(SeqStack* stack){
    if(stack == NULL)return;
    for(int i = 0;i < stack->size;i++){
        stack->data[i] = NULL;
    }
}

//销毁
void FreeSpace_SeqStack(SeqStack* stack){
    if(stack == NULL)return;
    free(stack);
}
