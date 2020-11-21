//2020年10月27日 15:18:25
//测试二叉树

#include <stdio.h>
#include "binaryTree.h"

int main()
{
    printf("请输入根结点元素：");
    Tree T = CreatBinaryTree();
    //Tree T = CreatBinaryTreeByLevel();

    printf("先序遍历结果：");
    PreorderTraversal(T);
    printf("\n");

    printf("中序遍历结果：");
    InorderTraversal(T);
    printf("\n");

    printf("后序遍历结果：");
    PostorderTraversal(T);
    printf("\n");

    printf("非递归先序遍历结果：");
    PreorderNonRecursion(T);

    printf("非递归后序序遍历结果：");
    PostorderNonRecursion(T);


    //printf("层序遍历结果：");
    //LevelTraversal(T);

    printf("树的深度：%d\n", Depth(T));
    printf("叶子结点个数：%d\n", GetLeafNodeNum(T));

    DisposeBinaryTree(T);
}