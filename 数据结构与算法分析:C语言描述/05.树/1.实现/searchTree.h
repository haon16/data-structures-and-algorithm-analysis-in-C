//2020年10月28日21点45分
//二叉查找树的实现

#ifndef _SearchTree_H

#include "../../base.h"

struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;

//创建一棵空树
SearchTree MakeEmpty(SearchTree T);

//查找指定元素
Position Find(ElementType X, SearchTree T);

//查找最小值
Position FindMin(SearchTree T);

//查找最大值
Position FindMax(SearchTree T);

//插入元素
SearchTree Insert(ElementType X, SearchTree T);

//删除元素
SearchTree Delete(ElementType X, SearchTree T);

//获取该结点的元素
ElementType Retrieve(Position P);

//中序遍历(按顺序从小到大输出)
void InorderTraversal(SearchTree T);

#endif      /* _SearchTree_H */