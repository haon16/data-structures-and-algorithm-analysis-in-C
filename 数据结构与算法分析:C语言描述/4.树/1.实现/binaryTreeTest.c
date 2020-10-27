//2020年10月27日 15:18:25
//测试二叉树

#include "binaryTree.h"

int main()
{
    printf("请输入根结点元素：");
    Tree T = CreatBinaryTree();

    printf("先序遍历结果：");
    PreorderTraversal(T);
    printf("\n");

    printf("中序遍历结果：");
    InorderTraversal(T);
    printf("\n");

    printf("后序遍历结果：");
    PostorderTraversal(T);
    printf("\n");

    printf("层序遍历结果：");
    LevelTraversal(T);

    printf("树的深度：%d\n", Depth(T));
}