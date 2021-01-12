//2020年10月27日 14:45:06
//二叉树的实现

#ifndef _BinaryTree_H
#define _BinaryTree_H

#include "../../base.h"

typedef struct TreeNode *PtrToTreeNode;
typedef PtrToTreeNode Tree;

//创建二叉树
Tree CreatBinaryTree();

//按层创建二叉树
Tree CreatBinaryTreeByLevel();

//先序遍历
void PreorderTraversal(Tree T);

//中序遍历
void InorderTraversal(Tree T);

//后续遍历
void PostorderTraversal(Tree T);

//非递归先序遍历
void PreorderNonRecursion(Tree T);

//非递归后序遍历
void  PostorderNonRecursion(Tree T);

//层序遍历
void LevelTraversal(Tree T);

//求二叉树深度
int Depth(Tree T);

//获取叶子结点个数
int GetLeafNodeNum(Tree T);

//销毁树
void DisposeBinaryTree(Tree T);

#endif      /* _BinaryTree_H */