//时间：2019年7月26日10:22:22
//无空头链表

#include <stdio.h>
#include <stdlib.h>

//定义结点结构体
struct Node
{
	int data;
	struct Node *pNext;
};

//定义全局变量的头尾指针
struct Node *g_pHead = NULL;
struct Node *g_pEnd = NULL;

//创建链表，在链表中添加一个数据，尾添加
void AddNodeToListTail(int val);

//创建链表，在链表中添加一个数据，头添加
void AddNodeToListHead(int val);

//遍历链表
void ListTraversal();

//查找指定数据的结点
struct Node * findNodeFromList(int val);

//指定数据后插入结点
void AddListRand(int index, int val);

//清空链表
void clearList();

//头删除结点
void DeleteNodeFromListHead();

//尾删除结点
void DeleteNodeFromListTail();

//删除指定数据的结点
void deleteNodeFromList(int val);
/*
int main()
{
	AddNodeToListHead(1);
	AddNodeToListHead(2);
	AddNodeToListHead(3);
	AddNodeToListHead(4);
	AddNodeToListHead(5);
	AddNodeToListHead(6);
	AddNodeToListHead(7);
	ListTraversal();

	deleteNodeFromList(4);
	ListTraversal();
	AddNodeToListTail(12);
	AddListRand(1, 50);
	ListTraversal();
	clearList();
	system("pause");
	return 0;
}
*/
//尾添加结点
void AddNodeToListTail(int val)
{
	//生成新结点
	struct Node *pNew = (struct Node *)malloc(sizeof(struct Node));
	pNew->data = val;
	pNew->pNext = NULL;

	//链接
	if (NULL == g_pHead)  //链表为空
	{
		g_pHead = pNew;
		g_pEnd = pNew;
	}
	else   //链表不为空
	{
		g_pEnd->pNext = pNew;
		g_pEnd = pNew;
	}
	//g_pEnd = pNew; 重复了可统一写在下面
}

//头添加结点
void AddNodeToListHead(int val)
{
	//生成新结点
	struct Node *pNew = (struct Node *)malloc(sizeof(struct Node));
	pNew->data = val;
	pNew->pNext = NULL;

	//链接
	if (NULL == g_pHead)   //链表为空
	{
		g_pHead = pNew;   
		g_pEnd = pNew;
	}
	else   //链表不为空
	{
		pNew->pNext = g_pHead;
		g_pHead = pNew;
	}
	//g_pHead = pNew;; 重复了可统一写在下面
}

//遍历链表
void ListTraversal()
{
	//生成临时结点
	struct Node *pTemp = g_pHead;
	//遍历
	while (pTemp != NULL)
	{
		printf("%d  ", pTemp->data);
		pTemp = pTemp->pNext;
	}
	printf("\n");
}

//查找指定结点
struct Node * findNodeFromList(int val)
{
	//生成临时结点
	struct Node *pTemp = g_pHead;

	//遍历
	while (pTemp != NULL)
	{
		if (val == pTemp->data)
		{
			return pTemp;
		}
		pTemp = pTemp->pNext;
	}
	//没找到返回NULL
	return NULL;
}

//指定位置插入结点
void AddListRand(int index, int val)
{
	//链表为空    
	if (NULL == g_pHead)
	{
		printf("链表没有结点\n");
		return;
	}

	//查找结点
	struct Node *pTemp = findNodeFromList(index);    //找到和找不到两个可能，找不到的话包括链表为空的情况

	//结点不存在
	if (NULL == pTemp)
	{
		printf("没有指定节点\n");
		return;
	}

	//结点存在
	struct Node *pNew = (struct Node *)malloc(sizeof(struct Node));
	pNew->data = val;
	pNew->pNext = NULL;

	//***链接要考虑指定位置是否为尾结点***
	if (pTemp == g_pEnd)
	{
		g_pEnd->pNext = pNew;
		g_pEnd = pNew;
	}
	else
	{
		pNew->pNext = pTemp->pNext;
		pTemp->pNext = pNew;
	}
}

//清空链表
void clearList()
{
	struct Node *pTemp = g_pHead;
	while (g_pHead != NULL)
	{
		pTemp = g_pHead;
		g_pHead = g_pHead->pNext;
		free(pTemp);
	}
	//头尾清空
	g_pEnd = NULL;
	g_pHead = NULL;
}

//头删除结点
void DeleteNodeFromListHead()
{
	if (NULL == g_pHead)    //链表为空
	{
		printf("链表为空,无须施放\n");
		return;
	}
	else if (g_pHead == g_pEnd)   //只有一个结点
	{
		free(g_pHead);
		g_pHead = NULL;
		g_pEnd = NULL;
	}
	else            //一个结点以上
	{
		struct Node *pTemp = g_pHead;
		g_pHead = g_pHead->pNext;
		free(pTemp);
	}
}

//尾删除结点
void DeleteNodeFromListTail()
{
	if (NULL == g_pHead)    //链表为空
	{
		printf("链表为空,无须施放\n");
		return;
	}
	else if (g_pHead == g_pEnd)   //只有一个结点
	{
		free(g_pHead);
		g_pHead = NULL;
		g_pEnd = NULL;
	}
	else  //一个结点以上
	{
		struct Node *pTemp = g_pHead;
		while (pTemp->pNext != g_pEnd)   //遍历寻找尾结点的前一个结点
		{
			pTemp = pTemp->pNext;
		}
		free(g_pEnd);
		g_pEnd = pTemp;
		g_pEnd->pNext = NULL;
	}
}

//删除指定数据的结点
void deleteNodeFromList(int val)
{
	//链表判断
	if (NULL == g_pHead)
	{
		printf("链表为NULL，无需释放\n");
		return;
	}

	struct Node *pTemp = findNodeFromList(val);
	if (NULL == pTemp)
	{
		printf("查无此结点\n");
		return;
	}

	if (pTemp == g_pHead)   //删除的是头结点
	{
		DeleteNodeFromListHead();
	}
	else if (pTemp == g_pEnd)   //删除的是尾结点
	{
		DeleteNodeFromListTail();
	}
	else             //删除的是中间结点
	{
		struct Node *pt = g_pHead;
		while (pt->pNext != pTemp)
		{
			pt = pt->pNext;
		}
		pt->pNext = pTemp->pNext;
		free(pTemp);
	}

}

