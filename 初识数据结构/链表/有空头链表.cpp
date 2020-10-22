//时间：2019年7月26日14:49:06
//有空头链表

#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *pNext;
};

//头尾指针定义
struct Node *g_pHead = NULL;
struct Node *g_pEnd = NULL;

//创建空头
void InitListHead();

//创建新结点
struct Node *CreateNode(int val);

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

//删除头结点（第一个有效结点）
void DeleteListHead();

//删除尾结点
void DeleteListTail();

//删除指定结点
void DeleteListRand(int val);

//释放链表
void freeList();

int main()
{
	InitListHead();
	
	AddListTail(8); 
	ListTraversal();

	DeleteListHead();
	ListTraversal();

	AddListTail(10);
	ListTraversal();


	system("pause");
	return 0;
}

//创建空头结点
void InitListHead()
{
	//创建空头结点
	g_pHead = (struct Node *)malloc(sizeof(struct Node));   //分配内存空间
	g_pHead->pNext = NULL;   
	g_pEnd = g_pHead;    //尾结点此时要跟头结点指向同一个地址
}

//创建新结点
struct Node *CreateNode(int val)
{
	struct Node *pNew = (struct Node *)malloc(sizeof(struct Node));
	//分配空间失败
	if (NULL == pNew)
	{
		return NULL;
	}
	//分配空间成功
	pNew->data = val;
	pNew->pNext = NULL;

	return pNew;
}

//链表尾添加
void AddListTail(int val)
{
	struct Node *pNew = CreateNode(val);
	if (NULL == pNew)
	{
		printf("分配内存空间失败，内存不足\n");
		return;
	}
	//链接
	g_pEnd->pNext = pNew;     //不论链表有无结点，都是尾结点的下一个结点是新结点
	g_pEnd = pNew;
}

//链表头添加
void AddListHead(int val)
{
	struct Node *pNew = CreateNode(val);
	if (NULL == pNew)
	{
		printf("分配内存空间失败，内存不足\n");
		return;
	}
	pNew->pNext = g_pHead->pNext;     //不论链表有无结点，都是新结点的下一个结点是空头结点的下一个结点
	g_pHead->pNext = pNew;

	if (g_pEnd == g_pHead)       //如果添加前链表为空，此时空头结点和尾结点是指向同一块内存空间，添加后尾结点要后移
	{
		g_pEnd = pNew;
	}
	
}

//指定位置添加
void AddListRand(int index, int val)
{
	struct Node *pTemp = FindNode(index);   //也可以先判断是否为空在查找

	if (NULL == pTemp)
	{
		printf("查无此结点，无法添加!\n");
		return;
	}

	struct Node *pNew = CreateNode(val);
	if (NULL == pNew)
	{
		printf("分配内存空间失败，内存不足\n");
		return;
	}
	                                       //或者直接if判断是否pTemp是尾结点，是的话调用尾添加，不是的话再进行操作
	pNew->pNext = pTemp->pNext;
	pTemp->pNext = pNew;

	if (pTemp == g_pEnd)    //如果指定的位置是尾结点则尾结点标记要指向新结点
	{
		g_pEnd = pNew;
	}
}

//查找指定结点，并返回结点地址
struct Node *FindNode(int val)
{
	if (NULL == g_pHead->pNext)
	{
		printf("链表为空，无法查找");
		return NULL;
	}

	struct Node *pTemp = g_pHead->pNext;
	while (pTemp != NULL)
	{
		if (val == pTemp->data)
		{
			//找到了
			return pTemp; 
		}
		pTemp = pTemp->pNext;
	}
	//没找到
	return NULL;
}

//遍历输出链表
void ListTraversal()
{
	if (NULL == g_pHead->pNext)
	{
		printf("链表为空\n");
		return;
	}

	struct Node *pTemp = g_pHead->pNext;
	while (pTemp != NULL)
	{
		printf("%d  ", pTemp->data);
		pTemp = pTemp->pNext;
	}
	printf("\n");
}

//删除头结点（第一个有效结点）
void DeleteListHead()
{
	if (NULL == g_pHead->pNext)
	{
		printf("链表为空，无法继续删除！\n");
		return;
	}
	//链表不为空
	struct Node *pTemp = g_pHead->pNext;
	g_pHead->pNext = pTemp->pNext;

	//if (pTemp == g_pEnd)   //如果链表中只剩一个有效结点，这个结点是尾结点，删除后尾结点要重新指向空头结点指向的空间；
	//{
	//	g_pEnd = g_pHead;
	//}
	free(pTemp);
}

//删除尾结点
void DeleteListTail()
{
	if (NULL == g_pHead->pNext)
	{
		printf("链表为空，无法继续删除！\n");
		return;
	}

	if (g_pHead->pNext == g_pEnd)    //如果只有一个有效结点，这个节点就是尾结点，删除后尾结点要重新指向空头结点指向的空间
	{
		g_pHead->pNext = NULL;
		free(g_pEnd);
		g_pEnd = g_pHead;
	}
	else
	{
		//找尾结点的前一个结点
		//写法1
		struct Node *pTemp = g_pHead->pNext;
		while (pTemp->pNext != g_pEnd)   //链表有多个结点，因为尾结点在第一个有效结点的情况已经考虑过，所以可以直接从第二个有效结点开始找
		{
			pTemp = pTemp->pNext;
		}
		free(g_pEnd);
		pTemp->pNext = NULL;
		g_pEnd = pTemp;

		//写法2
		/*struct Node *pTemp = g_pHead->pNext;
		while (pTemp != NULL)
		{
			if (pTemp->pNext == g_pEnd)
			{
				break;
			}
			pTemp = pTemp->pNext;
		}
		free(g_pEnd);
		pTemp->pNext = NULL;
		g_pEnd = pTemp;*/
	}
}

//删除指定结点
void DeleteListRand(int val)
{
	if (NULL == g_pHead->pNext)
	{
		printf("链表为空，无法继续删除！\n");
		return;
	}

	//没有找到指定结点
	struct Node *pTemp = FindNode(val);
	if (NULL == pTemp)
	{
		printf("查无此结点，无须删除!\n");
		return;
	}

	if (pTemp == g_pEnd)   //指定结点是尾结点
	{
		DeleteListTail();
	}
	else           //指定结点不是尾结点
	{
		struct Node *pt = g_pHead;
		while (pt->pNext != pTemp)     //从第一个有效结点开始遍历
		{
			pt = pt->pNext;
		}
		pt->pNext = pTemp->pNext;
		free(pTemp);
	}
}

//释放链表
void freeList()
{
	struct Node *pTemp = g_pHead; // g_pHead->pNext /  g_pHead    //如果是程序结束施放链表需要把空头结点也删除，如果是打算删除后还可以继续添加就不能删除
	while (pTemp != NULL)
	{
		struct Node *pT = pTemp;
		pTemp = pTemp->pNext;
		free(pT);
	}
	g_pEnd = NULL;
	g_pHead = NULL;
}
