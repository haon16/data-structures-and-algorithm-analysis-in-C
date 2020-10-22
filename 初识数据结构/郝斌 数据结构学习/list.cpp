# include <stdio.h>
# include <malloc.h>
# include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node * pNext;
}NODE, *PNODE;                     //NODE等价于struct Node  PNODE等价于struct Node *

//函数声明
PNODE create_list(void);
void traverse_list(PNODE pHead);
bool is_empty(PNODE);
int length_list(PNODE);
bool insert_list(PNODE, int , int);
bool delete_list(PNODE, int , int *);
void sort_list(PNODE);


int main(void)
{
	int val;
	PNODE pHead = NULL;
	pHead = create_list();       //创建一个非循环单链表，并将该链表的头结点赋给pHead
	traverse_list(pHead);
	int len = length_list(pHead);
	printf("链表长度为%d\n", len);
	sort_list(pHead);
	traverse_list(pHead);

	if(insert_list(pHead, 0, 5))
	{
		printf("链表插入数据成功\n");
	}
	else
	{
		printf("链表插入数据失败\n");
	}
	traverse_list(pHead);

	if( delete_list(pHead, 4, &val) )
	{
		printf("删除成功，您删除的元素是:%d\n", val);
	}
	else
	{
		printf("删除失败!您删除的元素不存在\n");
	}
	traverse_list(pHead);

	if( is_empty(pHead))
	{
		printf("链表为空\n");
	}
	else
	{
		printf("链表不为空\n");
	}

	
	return 0;
}

PNODE create_list(void)
{
	int len;
	int i;
	int val;  //临时存放用户输入的结点的值
    
	//分配一个不存放有效数据的头结点
	PNODE pHead = (PNODE)malloc( sizeof(NODE) );
	if( NULL == pHead )
	{
		printf("分配失败。程序终止！\n");
		exit(-1);
	}
	PNODE pTail = pHead;
	pTail->pNext = NULL;
	
	printf("请输入您需要生成的链表结点的个数：len = ");
	scanf("%d", &len);
	
	for(i=0; i<len; ++i)
	{
		printf("请输入第%d个结点的值：", i+1);
		scanf("%d", &val);
		
		PNODE pNew = (PNODE)malloc( sizeof(NODE));
		if( NULL == pHead )
		{
			printf("分配失败。程序终止！\n");
			exit(-1);
		}
		pNew->data = val;
		pTail->pNext = pNew;
		pNew->pNext = NULL;
		pTail = pNew;
	}
	return pHead;
}

void traverse_list(PNODE pHead)
{
	PNODE p = pHead->pNext;

	while( NULL != p)
	{
		printf("%d ", p->data);
		p = p->pNext;
	}
	printf("\n");

	return;
}

bool is_empty(PNODE pHead)
{
	if (NULL == pHead->pNext)
		return true;
	else
		return false;
}

int length_list(PNODE pHead)
{
	PNODE p = pHead->pNext;
	int len = 0;

	while( NULL != p)
	{
		++len;
		p = p->pNext;
	}

	return len;
}

void sort_list(PNODE pHead)
{
/*	int i, j, t;
	int len = length_list(pHead);
	PNODE p, q;
	
	for(i=0,p=pHead->pNext; i<len; ++i,p=p->pNext)             //for(p=pHead->pNext; p!=NULL; p=p->pNext)
	{
		for(j=i+1,q=p->pNext; j<len-1; ++j,q=q->pNext)         //for(q=p->pNext; q!=NULL; q=q->pNext)
		{
			if(p->data > q->data)
			{
				t = p->data;
				p->data = q->data;
				q->data = t;
			}
		}
	}
*/
	PNODE p = pHead->pNext;
	PNODE q = p->pNext;
	int t;
	while(p != NULL)
	{
		q = p->pNext;
		while(q != NULL)
		{
			if(p->data > q->data)
			{
				t = p->data;
				p->data = q->data;
				q->data = t;
			}
			q = q->pNext;
		}
		p = p->pNext;
	}

	return;
}

bool insert_list(PNODE pHead, int pos, int val)
{
	int i = 0;
	PNODE p = pHead;

	while(NULL!=p && i<pos-1)     //pos>1,while循环才成立
	{
		p = p->pNext;
		++i;
	}
	if(i>pos-1 || NULL==p)                 //i > pos -1是防止别人输入的pos参数为0或者负数。这都与题意不符合。NULL == p呢，是防止整个链表的长度都还没有pos长，即不存在pos这个位置可以插入。
		return false;
	PNODE pNew = (PNODE)malloc( sizeof(NODE) );
	if(NULL == pNew)
	{
		printf("动态分配内存失败");
		exit(-1);
	}
	pNew->data = val;
	PNODE q = p->pNext;
	p->pNext = pNew;
	pNew->pNext = q;
		
/*	int len;
	len = length_list(pHead);
	if(pos<1 || pos>len+1)
	{
		return false;
	}

	int i;
	PNODE p = pHead;
	PNODE q = (PNODE)malloc( sizeof(NODE) );
	if(NULL == q)
	{
		printf("动态分配内存失败");
		exit(-1);
	}
    
	for(i=1; i<pos; ++i)
	{
		p = p->pNext;
	}

	q->data = val;
	q->pNext = p->pNext;
	p->pNext = q;
*/
	return true;
}

bool delete_list(PNODE pHead, int pos, int * val)
{
	int i = 0;
	PNODE p = pHead;

	while(NULL!=p->pNext && i<pos-1)
	{
		p = p->pNext;
		++i;
	}
	if(i>pos-1 || NULL==p->pNext)
		return false;

	PNODE q = p->pNext;                         
	*val = q->data;

	//删除p后面的结点
	p->pNext = p->pNext->pNext;
	free(q);                           //把节点1指针域指针指向节点3，但不要忘记释放节点2所占的内存，否则将会造成内存泄漏
	q = NULL;

	return true;
}
