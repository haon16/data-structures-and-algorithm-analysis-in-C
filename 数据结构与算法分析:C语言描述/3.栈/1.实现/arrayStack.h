//2020年10月23日18点20分
//栈的数组实现

#ifndef _ArrayStack_H

#include "../../base.h"

struct StackRecord;
typedef struct StackRecord *Stack;

//检测栈是否为空
int IsEmpty(Stack S);

//检测栈是否满
int IsFull(Stack S);

//创建栈
Stack CreateStack(int MaxElements);

//销毁栈
void DisposeStack(Stack S);

//构造空栈
void MakeEmpty(Stack S);

//进栈
void Push(ElementType X, Stack S);

//返回栈顶元素
ElementType Top(Stack S);

//出栈
void Pop(Stack S);

//返回栈顶元素并出栈
ElementType TopAndPop(Stack S);

//遍历输出栈
void PrintStack(Stack S);

#endif      /* _ArrayStack_H */