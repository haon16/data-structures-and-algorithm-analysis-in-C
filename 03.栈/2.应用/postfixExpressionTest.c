//2020年10月26日 16:07:18
//测试后缀表达式求计算结果

#include <stdio.h>
#include "postfixExpression.h"
#include "infixToPostfixConversion.h"
#include "../../base.h"

int main()
{
    FILE* fp = fopen("postfixExpression.txt", "r");
    if(fp == NULL)
        FatalError("Not a corrent path");
    
    printf("计算结果：%d\n", GetPostfixExpressionRes(fp));

    return 0;
}