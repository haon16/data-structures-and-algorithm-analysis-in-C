//2020年10月22日 10:15:02
//链表实现

#ifndef _List_H

#include "../../base.h"

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

//生成空链表
List MakeEmpty(List L);

//判断链表是否为空
int IsEmpty(List L);

//判断结点P是否为尾结点
int IsLast(Position P, List L);

//查找链表中数据项为X的第一个结点
Position Find(ElementType X, List L);

//删除链表中数据项为X的第一个结点
void Delete(ElementType X, List L);

//查找链表中数据项为X的第一个结点的前驱
Position FindPrevious(ElementType X, List L);

//在链表中指定位置P插入数据项为X的结点
void Insert(ElementType X, List L, Position P);

//删除链表中除头结点外的所有结点
void DeleteList(List L);

//获得链表中头结点位置
Position Header(List L);

//获得链表中第一个数据结点的位置
Position First(List L);

//获得指定结点的后继结点
Position Advance(Position P);

//获得指定结点的数据项
ElementType Retrieve(Position P);

//遍历输出链表
void PrintList(List L);

#endif      /* _List_H */