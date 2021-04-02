/*************************************************************************
    > File Name: B_Tree.c
    > Author: 郭耀龙
    > Mail: 1373766226@qq.com 
    > Created Time: Fri 02 Apr 2021 12:12:00 AM CST
    > Function: 
        求叶子结点数目：
            没有子结点即为叶子结点：D、E、H
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

// 遍历二叉树——前序
void Recursion(BINARYNODE* root)
{
    if(root == NULL)return;
    // 根左右
    printf("%c ",root->ch);
    Recursion(root->lchild);
    Recursion(root->rchind);
}

// 拷贝二叉树
BINARYNODE* CopyBinaryTree(BINARYNODE* root)
{
    if(root == NULL)return NULL;

    //拷贝左子树
    BINARYNODE* lchild = CopyBinaryTree(root->lchild);
    //拷贝右子树
    BINARYNODE* rchild = CopyBinaryTree(root->rchind);

    //申请空间
    BINARYNODE* newNode = (BINARYNODE*)malloc(sizeof(BINARYNODE));
    //根节点赋值
    newNode->ch = root->ch;
    newNode->lchild = lchild;
    newNode->rchind = rchild;

    return newNode;
}

//释放二叉树
void FreeSpaceBinaryTree(BINARYNODE* root)
{
    if(root == NULL)return;
    //释放左子树
    FreeSpaceBinaryTree(root->lchild);
    //释放右子树
    FreeSpaceBinaryTree(root->rchind);
    //释放根节点
    free(root);
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

    BINARYNODE* root = CopyBinaryTree(&NodeA);
    Recursion(root);
    FreeSpaceBinaryTree(root);
}

int main(int argc, const char* argv[])
{

    CreateBinaryTree();

	return 0;
}
