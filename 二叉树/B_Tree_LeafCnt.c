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

void CaculateLeafNum(BINARYNODE* root, int *leafNum)
{
    // 终止条件
    if(root == NULL)return;

    // 如果左子树和右子树都为空，说明为叶子结点
    if(root->lchild == NULL && root->rchind == NULL){
        (*leafNum)++;
    }
    // 左子树叶子结点数目
    CaculateLeafNum(root->lchild, leafNum);
    // 右子树叶子结点数目
    CaculateLeafNum(root->rchind, leafNum);
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

    int leafNum = 0;
    CaculateLeafNum(&NodeA,&leafNum);
    printf("leafNum = %d\n",leafNum);
}

int main(int argc, const char* argv[])
{

    CreateBinaryTree();

	return 0;
}
