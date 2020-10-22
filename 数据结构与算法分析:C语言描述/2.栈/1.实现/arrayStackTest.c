//2020年10月23日18点20分
//测试数组实现的栈

#include <stdio.h>
#include "arrayStack.h"

int main()
{
    Stack S = CreateStack(10);

    printf("栈S%s为空\n", IsEmpty(S)?"":"不");

    Push(1, S);
    Push(3, S);
    Push(5, S);
    Push(7, S);
    Push(9, S);
    PrintStack(S);

    printf("两次出栈后：");
    Pop(S);
    Pop(S);
    PrintStack(S);

    DisposeStack(S);
}