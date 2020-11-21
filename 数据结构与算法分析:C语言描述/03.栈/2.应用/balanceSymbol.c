//2020年10月23日22点11分
//栈的应用：平衡符号

#include <stdio.h>
#include <string.h>
#include "../1.实现/linkedStack.h"
#include "balanceSymbol.h"

const char open_char[] = "([{";
const char close_char[] = ")]}";

void CheckBalanceSymbol(FILE *fp)
{
    if(fp == NULL)
        FatalError("fp == NULL");

    Stack S = CreateStack();
    char ch;
    while((ch = fgetc(fp)) != EOF)
    {
        printf("%c", ch);
        if(IsOpenSymbol(ch) > -1)
        {
            Push(ch, S);
        }
        else if(IsCloseSymbol(ch) > -1)
        {
            if(IsEmpty(S))
                FatalError("Symbol mismatch 1");
            
            char chOpen = Top(S);
            if (!IsMatch(chOpen, ch))
                FatalError("Symbol mismatch 2");

            printf("\n弹出元素为：%c\n", chOpen);
            Pop(S);
        }
    }
    printf("\n");               //printf ""
    if(!IsEmpty(S))
        FatalError("Symbol mismatch 3");

    printf("输入无误\n");
    fclose(fp);
    DisposeStack(S);
}

int IsOpenSymbol(char ch)
{
    int i = 0;
    while(open_char[i] != '\0')
    {
        if(ch == open_char[i])
            return i;
        i++;
    }
    return -1;
}

int IsCloseSymbol(char ch)
{
    int i = 0;
    while(close_char[i] != '\0')
    {
        if(ch == close_char[i])
            return i;
        i++;
    }
    return -1;
}

int IsMatch(char chOpen, char chClose)
{
    return IsOpenSymbol(chOpen) == IsCloseSymbol(chClose);
}