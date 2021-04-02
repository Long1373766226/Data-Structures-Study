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

//求二叉树的高度
int CaculateTreeDepth(BINARYNODE* root)
{
    // 终止条件
    if(root == NULL)return 0;

    int depth = 0;
    // 求左子树的高度
    int leftDepth = CaculateTreeDepth(root->lchild);
    int rightDepth = CaculateTreeDepth(root->rchind);
    depth = (leftDepth > rightDepth) ? (leftDepth + 1) : (rightDepth + 1);

    return depth;
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

    int depth = CaculateTreeDepth(&NodeA);
    printf("树的高度为 = %d\n",depth);
}

int main(int argc, const char* argv[])
{

    CreateBinaryTree();

	return 0;
}
