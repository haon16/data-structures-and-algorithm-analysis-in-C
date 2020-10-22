# include <stdio.h>
# include <malloc.h>
# include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node * pNext;
}NODE, * PNODE;

typedef struct stack
{
	PNODE pTop;
	PNODE pBottom;
}STACK, *PSTACK;

void init(PSTACK);
void push(PSTACK, int);
void traverse(PSTACK);
bool pop(PSTACK, int *);
bool empty(PSTACK);
void clear(PSTACK);

int main(void)
{
	STACK S;
    int val;
	
	init(&S);        //目的是造出一个空栈
	push(&S, 1);     //压栈
	push(&S, 2);
	push(&S, 3);
	push(&S, 4);
	push(&S, 5);
	traverse(&S); 
	clear(&S);
	traverse(&S); 
	
	if( pop(&S, &val) )
	{
		printf("出栈成功，出栈的元素是%d\n",val);
	}
	else
	{
		printf("出栈失败！\n");
	}
	traverse(&S);    //遍历输出
	
	return 0;
}

void init(PSTACK pS)
{
/*
PNODE pHead = (PNODE)malloc( sizeof(NODE) );
pS->pTop = pHead;
pS->pBottom = pHead;
	*/
	pS->pTop = (PNODE)malloc( sizeof(NODE));
	if(NULL == pS->pTop)
	{
		printf("动态内存分配失败");
		exit(-1);
	}
	else
	{
		pS->pBottom = pS->pTop;
		pS->pTop->pNext = NULL;  //pS->pBottom->pNext = NULL; 
	}
	
	return;
}

void push(PSTACK pS, int val)
{
	PNODE pNew = (PNODE)malloc( sizeof(NODE) );
	pNew->data = val;
	pNew->pNext = pS->pTop;
	pS->pTop = pNew;
	
	return;
}

void traverse(PSTACK pS)
{
	PNODE p = pS->pTop;
	
	while(p != pS->pBottom)
	{
		printf("%d ", p->data);
		p = p->pNext;
	}
	printf("\n");
	
	return;
}

bool empty(PSTACK pS)
{
	if(pS->pTop == pS->pBottom)
		return true;
	else
		return false;
}

//把pS所指向的栈出栈一次，并把出栈的元素存入pVal形参所指向的变量中，如果出栈失败，返回false,否则返回true
bool pop(PSTACK pS, int * pVal)
{
	if( empty(pS) )
	{
		return false;
	}
	else
	{
		PNODE r = pS->pTop;
		*pVal = r->data;
		pS->pTop = r->pNext;
		free(r);
		r = NULL;
		return true;
	}
}

//clear清空
void clear(PSTACK pS)
{
	if( empty(pS) )
	{
		return;
	}
	else
	{
		PNODE p = pS->pTop;
		PNODE q = NULL;

		while(p != pS->pBottom)
		{
			q = p->pNext;
			free(p);
			p = q;
		}
		pS->pTop = pS->pBottom;
	}
}