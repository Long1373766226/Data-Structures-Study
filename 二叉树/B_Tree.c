/*************************************************************************
    > File Name: B_Tree.c
    > Author: 郭耀龙
    > Mail: 1373766226@qq.com 
    > Created Time: Fri 02 Apr 2021 12:12:00 AM CST
    > Function: 
        先序遍历：根左右
        中序遍历：左根右
        后续遍历：左右根
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>

//二叉树结点
typedef struct BINARYNODE{
    char ch;
    struct BINARYNODE* lchild;  // 左孩子
    struct BINARYNODE* rchind;  // 右孩子
}BINARYNODE;

// 先序遍历：根左右
void Recursion_F(BINARYNODE* root)
{
    // 终止条件
    if(root == NULL)return;
    // 先访问根节点
    printf("%c ",root->ch);
    // 遍历左字数
    Recursion_F(root->lchild);
    // 遍历右字数    
    Recursion_F(root->rchind);
}

// 、中序遍历：左根右
void Recursion_M(BINARYNODE* root)
{
    // 终止条件
    if(root == NULL)return;
    // 遍历左字数
    Recursion_M(root->lchild);
    // 先访问根节点
    printf("%c ",root->ch);
    // 遍历右字数    
    Recursion_M(root->rchind);
}

// 后序遍历：左右根
void Recursion_B(BINARYNODE* root)
{
    // 终止条件
    if(root == NULL)return;
    // 遍历左字数
    Recursion_B(root->lchild);
    // 遍历右字数    
    Recursion_B(root->rchind);
    // 先访问根节点
    printf("%c ",root->ch);
}

void CreateBinaryTree()
{
    // 创建结点
    BINARYNODE NodeA = {'A',NULL,NULL};
    BINARYNODE NodeB = {'B',NULL,NULL};
    BINARYNODE NodeC = {'C',NULL,NULL};
    BINARYNODE NodeD = {'D',NULL,NULL};
    BINARYNODE NodeE = {'E',NULL,NULL};
    BINARYNODE NodeF = {'F',NULL,NULL};
    BINARYNODE NodeG = {'G',NULL,NULL};
    BINARYNODE NodeH = {'H',NULL,NULL};

    // 建立结点关系
    NodeA.lchild = &NodeB;
    NodeA.rchind = &NodeF;
    NodeB.rchind = &NodeC;
    NodeC.lchild = &NodeD;
    NodeC.rchind = &NodeE;
    NodeF.rchind = &NodeG;
    NodeG.lchild = &NodeH;

    // 递归遍历——先序遍历
    printf("前序遍历：");
    Recursion_F(&NodeA);
    printf("\n");

    // 递归遍历——中序遍历
    printf("中序遍历：");
    Recursion_M(&NodeA);
    printf("\n");

    // 递归遍历——后序遍历
    printf("后序遍历：");
    Recursion_B(&NodeA);
    printf("\n");
}

int main(int argc, const char* argv[])
{

    CreateBinaryTree();

	return 0;
}
