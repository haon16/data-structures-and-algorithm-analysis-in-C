//2020年10月26日 15:05:24
//栈的应用：后缀表达式

#include "postfixExpression.h"
#include "../1.实现/linkedStack.h"

int GetPostfixExpressionRes(FILE *fp)
{
    if(fp == NULL)
        FatalError("fp == NULL");

    Stack S = CreateStack();
    char buf[10];
    while(fscanf(fp, "%s", buf) != EOF)
    {
        if(buf[0] >= '0' && buf[0] <= '9')
        {
            Push(atoi(buf), S);
        }
        else
        {
            int b = Top(S);
            Pop(S);
            int a = Top(S);
            Pop(S);
            int res = 0;
            switch(buf[0])
            {
                case '+':
                    res = a + b;
                    break;
                case '-':
                    res = a - b;
                    break;
                case '*':
                    res = a * b;
                    break;
                case '/':
                    res = a / b;
                    break;
                default:
                    FatalError("Abnormal symbol");
            }
            Push(res, S);
        }
    }
    return Top(S);
}