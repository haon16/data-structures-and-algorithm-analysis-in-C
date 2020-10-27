//2020年10月27日 14:45:06
//二叉树的实现

#ifndef _BinaryTree_H

#include "../../base.h"

typedef struct TreeNode *PtrToNode;
typedef PtrToNode Tree;

//创建二叉树
Tree CreatBinaryTree();

//先序遍历
void PreorderTraversal(Tree T);

//中序遍历
void InorderTraversal(Tree T);

//后续遍历
void PostorderTraversal(Tree T);

//层序遍历
void LevelTraversal(Tree T);

//求二叉树深度
int Depth(Tree T);

#endif      /* _BinaryTree_H */