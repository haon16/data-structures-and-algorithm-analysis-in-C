# include <stdio.h>
# include <malloc.h>

typedef struct Queue
{
	int * pBase;
	int front;
	int rear;
}QUEUE;

void init(QUEUE *);
bool en_queue(QUEUE *, int val);
void traverse_queue(QUEUE *);
bool is_full(QUEUE *);
bool is_empty(QUEUE *);
bool out_queue(QUEUE * pQ, int * val);


int main(void)
{
	int val;
	QUEUE Q;
	init(&Q);
	en_queue(&Q, 6);
	en_queue(&Q, 5);
	en_queue(&Q, 4);
	en_queue(&Q, 3);
	en_queue(&Q, 2);
	en_queue(&Q, 1);
	en_queue(&Q, 0);
	traverse_queue(&Q);
	if( out_queue(&Q, &val) )
	{
		printf("出队成功，出队的元素为：%d\n", val);
	}
	else
	{
		printf("出队失败!\n");
	}
	traverse_queue(&Q);

	return 0;
}

void init(QUEUE * pQ)
{
	pQ->pBase = (int *)malloc( sizeof(int) * 6 );
	pQ->front = 0;
	pQ->rear = 0;

	return;
}

bool is_full(QUEUE * pQ)
{
	if( (pQ->rear +1) % 6 == pQ->front )
		return true;
	else
		return false;
}

bool is_empty(QUEUE *pQ)
{
	if(pQ->front == pQ->rear)
		return true;
	else
		return false;
}

bool en_queue(QUEUE * pQ , int val)
{
	if( is_full(pQ))
	{
		return false;
	}
	else
	{
		*(pQ->pBase+pQ->rear) = val;     //pQ->pBase[pQ->rear]
		pQ->rear = (pQ->rear + 1) % 6;

		return true;
	}
}

void traverse_queue(QUEUE * pQ)
{
	int t;
	for(t=pQ->front; t<pQ->rear; t=(t+1)%6)
	{
		printf("%d ", pQ->pBase[t]);
	}
	printf("\n");

	return;
}

bool out_queue(QUEUE * pQ, int * pVal)
{
	if( is_empty(pQ) )
	{
		return false;
	}
	else
	{
		*pVal = pQ->pBase[pQ->front];
		pQ->front = (pQ->front + 1) % 6;

		return true;
	}
}