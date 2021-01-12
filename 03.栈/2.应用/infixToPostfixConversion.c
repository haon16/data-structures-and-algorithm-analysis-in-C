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
    char buf[50];               //buf相关操作把转换后的表达式写入到指定文件中
    int cnt = 0;
    while((ch = getchar())!= '\n')
    {
        while(ch >= '0' && ch <= '9')
        {
            flag = 1;
            printf("%c", ch);
            buf[cnt++] = ch;
            ch = getchar();
        }
        
        if(flag == 1)
        {
            printf(" ");
            buf[cnt++] = ' ';
            flag = 0;
        }

        if(ch == '\n')
            break;
        
        if(ch == '+' || ch == '-')
        {
            while(!IsEmpty(S) && Top(S) != '(')
            {
                printf("%c ", Top(S));
                buf[cnt++] = Top(S);
                buf[cnt++] = ' ';
                Pop(S);
            }
            Push(ch, S);
        }        
        else if(ch == '*' || ch == '/')
        {
            while(!IsEmpty(S) && Top(S) != '(' && Top(S) != '+' && Top(S) != '-')
            {
                printf("%c ", Top(S));
                buf[cnt++] = Top(S);
                buf[cnt++] = ' ';
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
                buf[cnt++] = Top(S);
                buf[cnt++] = ' ';
                Pop(S);
            }
            if(Top(S) == '(')
                Pop(S);
        }
    }
    while(!IsEmpty(S))
    {
        printf("%c ", Top(S));
        buf[cnt++] = Top(S);
        buf[cnt++] = ' ';
        Pop(S);
    }
    printf("\n");
    buf[cnt++] = '\n';
    FILE* fp = fopen("postfixExpression.txt", "w");
    fwrite(buf, 1, cnt, fp);
    fclose(fp);
}
