//2020年10月25日12点19分
//栈的应用：中缀表达式到后缀表达式的转换

#include <stdio.h>
#include <string.h>
#include "../1.实现/linkedStack.h"
#include "infixToPostfixConversion.h"

void InfixToPostfixConversion()
{
    Stack S = CreateStack();

    printf("请输入表达式：");
    char ch;
    int flag = 0;
    while((ch = getchar())!= '\n')
    {
        while(ch >= '1' && ch <= '9')
        {
            flag = 1;
            printf("%c", ch);
            ch = getchar();
        }
        
        if(ch == '\n')
            break;
        if(flag == 1)
        {
            printf(" ");
            flag == 0;
        }
        
        if(ch == '+' || ch == '-')
        {
            while(!IsEmpty(S) && Top(S) != '(')
            {
                printf("%c ", Top(S));
                Pop(S);
            }
            Push(ch, S);
        }        
        else if(ch == '*' || ch == '/')
        {
            while(!IsEmpty(S) && Top(S) != '(' && Top(S) != '+' && Top(S) != '-')
            {
                printf("%c ", Top(S));
                Pop(S);
            }
            Push(ch, S);
        }
        else if(ch == '(')
        {
            Push(ch, S);
        }
        else if(ch == ')')
        {
            while(!IsEmpty(S) && Top(S) != '(')
            {
                printf("%c ", Top(S));
                Pop(S);
            }
            if(Top(S) == '(')
                Pop(S);
        }
    }
    while(!IsEmpty(S))
    {
        printf("%c ", Top(S));
        Pop(S);
    }
    printf("\n");
}
