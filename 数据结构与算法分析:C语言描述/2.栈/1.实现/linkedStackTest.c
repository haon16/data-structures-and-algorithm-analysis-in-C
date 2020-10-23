//2020年10月23日 16:46:27
//测试链表实现的栈

#include <stdio.h>
#include "linkedStack.h"

int main()
{
    Stack S = CreateStack();

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

    MakeEmpty(S);
    printf("栈S%s为空\n", IsEmpty(S)?"":"不");
    DisposeStack(S);
}