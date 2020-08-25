//时间：2019年7月26日20:46:48
//C++链表头文件

#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

//结点结构体
struct Node
{
	int data;
	struct Node *pNext;
};


class List
{
public:
	List();
	~List();

	//链表尾添加
	void AddListTail(int val);

	//链表头添加
	void AddListHead(int val);

	//指定位置添加
	void AddListRand(int index, int val);

	//查找指定位置
	struct Node *FindNode(int val);

	//遍历输出链表
	void ListTraversal();

	//删除指定结点
	void DeleteListRand(int val);

private:
	//头尾指针定义
	Node *g_pHead = NULL;   //C++ struct可不写
	Node *g_pEnd = NULL;

private:
	//创建空头,空头链表初始化
	void InitListHead();

	//创建新结点
	struct Node *CreateNode(int val);

	//删除头结点（第一个有效结点）
	void DeleteListHead();

	//删除尾结点
	void DeleteListTail();

	//释放链表
	void freeList();
};


