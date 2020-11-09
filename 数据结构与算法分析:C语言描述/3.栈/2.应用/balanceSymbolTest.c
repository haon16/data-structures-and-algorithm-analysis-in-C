//2020年10月23日22点11分
//测试栈实现的平衡符号

#include <stdio.h>
#include "balanceSymbol.h"
#include "../../base.h"

int main()
{
    FILE *fp = fopen("balanceSymbol.txt", "r");
    if(fp == NULL)
        FatalError("Not a corrent path");
    
    CheckBalanceSymbol(fp);

    return 0;
}