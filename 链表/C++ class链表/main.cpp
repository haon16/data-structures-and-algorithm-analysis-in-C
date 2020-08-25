//时间：2019年7月26日21:17:21
//c++ list主函数

#include <stdio.h>
#include <stdlib.h>
#include "list.h"


int main()
{
	List ls;

	ls.AddListHead(1);
	ls.AddListHead(1);
	ls.AddListHead(1);
	ls.AddListHead(1);
	ls.AddListHead(1);
	ls.AddListHead(1);

	ls.ListTraversal();

	ls.DeleteListRand(1);
	ls.ListTraversal();



	system("pause");
	return 0;
}
