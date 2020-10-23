//2020年10月22日 10:15:02
//测试链表

#include <stdio.h>
#include "list.h"

int main()
{
    List L = NULL;
    L = MakeEmpty(L);        //这边L要重新指向新的头结点 

    Insert(1, L, L);
    Insert(2, L, L);
    Insert(3, L, L);
    Insert(4, L, L);
    Insert(5, L, L);
    PrintList(L);

    int X;
    printf("请输入要查找的数：");
    scanf("%d", &X);
    char msg[20];
    sprintf(msg, "在链表中%s%d",Find(X, L)?"存在":"不存在", X);
    puts(msg);

    Delete(3,L);
    Delete(1,L);
    PrintList(L);

    DeleteList(L);
    PrintList(L);    
    return 0;
}