# include <stdio.h>
# include <malloc.h>
# include <stdlib.h>

struct Arr
{
	int * pBase;  //存储数组第一个元素的地址
	int len;      //数组所能容纳的最大元素的个数
	int cnt;      //当前数组有效个数
	//int increment; 自动增长因子
};

void init_arr(struct Arr * pArr, int length);
bool append_arr(struct Arr * pArr, int val);  //追加
bool insert_arr(struct Arr * pArr, int pos, int val);//pos的值从1开始  
bool delete_arr(struct Arr * pArr, int pos, int *pVal);//返回是否成功删除与所删除元素
int get();
bool is_empty(struct Arr * pArr);
bool is_full(struct Arr * pArr);
void sort_arr(struct Arr * pArr);
void show_arr(struct Arr * pArr);
void inversion_arr(struct Arr * pArr);


int main(void)
{
	struct Arr arr;
	int val;
	
	init_arr(&arr, 6);      //初始化
	show_arr(&arr);         //元素显示

	append_arr(&arr, 1);    //追加元素
	append_arr(&arr, 2);
	append_arr(&arr, 3);
	append_arr(&arr, 4);
	show_arr(&arr);
	printf("\n");

	if ( append_arr(&arr, 5) )
	{
		printf("追加成功!\n");
	}
	else
	{
		printf("追加失败!\n");
	}
	show_arr(&arr);
	printf("\n");

	//insert_arr(&arr, 6 , 99);         //元素插入
	if( insert_arr(&arr, 6, 99) )
	{
		printf("插入成功!\n");
	}
	else
	{
		printf("插入失败!\n");
	}
	show_arr(&arr);
	printf("\n");

	//delete_arr(&arr, 1, &val)
	if( delete_arr(&arr, 1, &val) )   //删除元素
	{
		printf("删除成功！\n");
		printf("您删除的元素是：%d\n", val);
	}
	else
	{
		printf("删除失败！\n");
	}
	show_arr(&arr);
	printf("\n");

    inversion_arr(&arr);    //数组元素倒置
	printf("倒置后");
	show_arr(&arr);
	printf("\n");

	sort_arr(&arr);         //元素排序
	printf("排序后");
	show_arr(&arr);
	printf("\n");

	return 0;
}

void init_arr(struct Arr * pArr, int length)
{
	pArr->pBase = (int *)malloc(sizeof(int) * length);
	if ( NULL == pArr->pBase)
	{
		printf("动态内存分配失败");
		exit(-1);
	}
	else
	{
		pArr->len = length;
		pArr->cnt = 0;
	}
	return;
}

void show_arr(struct Arr * pArr)
{
	int i;
	if ( is_empty(pArr) )
	{
		printf("数组为空\n");
	}
	else
	{
		printf("数组元素为：");
		for(i=0; i<pArr->cnt; ++i)
		{
			printf("%d ", pArr->pBase[i]);
		}
		printf("\n");
	}
	
	
}

bool is_empty(struct Arr * pArr)
{
	if (0 == pArr->cnt)
		return true;
	else
		return false;
	
}

bool is_full(struct Arr * pArr)
{
	if(pArr->cnt == pArr->len)
		return true;
	else
		return false;
}

bool append_arr(struct Arr * pArr, int val)
{
	//满时返回false
	if( is_full(pArr) )
		return false;
	//不满时追加
	else	
		pArr->pBase[pArr->cnt] = val;
	pArr->cnt++;
	return true;
}

bool insert_arr(struct Arr * pArr, int pos, int val)
{
	int i;
	
    if( is_full(pArr) )
		return false;
	
	if(pos<1 || pos>pArr->cnt+1)
		return false;
	
	for(i=pArr->cnt; i>=pos; i--)     //i=pArr->cnt-1;i>=pos-1;--i;
	{
		pArr->pBase[i] = pArr->pBase[i-1];  //pArr->pBase[i+1] = pArr->pBase[i]
		
	}
	pArr->pBase[i] = val;
	pArr->cnt++;
	return true;
}

bool delete_arr(struct Arr * pArr, int pos, int *pVal)
{
	int i;
	if( is_empty(pArr) )
		return false;
	if( pos<1 || pos>pArr->cnt )
		return false;
	
	*pVal = pArr->pBase[pos-1];
	for(i=pos; i<pArr->cnt; ++i)
	{
		pArr->pBase[i-1] = pArr->pBase[i];
	}
		pArr->cnt--;

		return true;
}

void inversion_arr(struct Arr * pArr)
{
	int i = 0;
	int j = pArr->cnt-1;
	int t;

	while(i < j)
	{
		t = pArr->pBase[j];
		pArr->pBase[j] = pArr->pBase[i];
		pArr->pBase[i] = t;
		++i;
		--j;
	}
	return;
}

void sort_arr(struct Arr * pArr)
{
	int i, j, t;

	for(i=0; i<pArr->cnt; ++i)
		for(j=i+1; j<pArr->cnt; ++j)
		{
			if(pArr->pBase[i] > pArr->pBase[j])
			{
				t = pArr->pBase[j];
				pArr->pBase[j] = pArr->pBase[i];
				pArr->pBase[i] = t;
			}

		}
}