#include "list.h"

int main()
{
    List L;
    MakeEmpty(L);

    Insert(1, L, L);
    Insert(2, L, L);
    Insert(3, L, L);
    Insert(4, L, L);
    Insert(5, L, L);
    PrintList(L);

    int X;
    printf("请输入要查找的数：");
    scanf(&X);
    char msg[20];
    sprintf(msg, "在链表中%s%d\n",Find(X, L)?"存在":"不存在", X);
    puts(msg);

    Delete(3,L);
    Delete(1,L);
    PrintList(L);

    DeleteList(L);
    PrintList(L);    

    return 0;
}