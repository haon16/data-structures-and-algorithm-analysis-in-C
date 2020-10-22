//2020年10月23日 16:46:27
//栈的链表实现

#ifndef _LinkedStack_H

#include "../../base.h"

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Stack;

//测试栈是否为空
int IsEmpty(Stack S);

//创建一个空栈
Stack CreateStack();

//释放栈资源
void DisposeStack(Stack S);

//清空栈
void MakeEmpty(Stack S);

//进栈
void Push(ElementType X, Stack S);

//返回栈顶元素
ElementType Top(Stack S);

//出栈
void Pop(Stack S);

//遍历输出栈
void PrintStack(Stack S);

#endif      /* _LinkedStack_H */

