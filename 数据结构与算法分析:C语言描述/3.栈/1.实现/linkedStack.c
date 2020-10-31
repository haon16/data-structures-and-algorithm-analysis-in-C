//2020年10月23日 16:46:27
//栈的链表实现

#include <stdio.h>
#include "linkedStack.h"

struct Node
{
    ElementType Element;
    PtrToNode Next;
};

int IsEmpty(Stack S)
{
    return S->Next == NULL;
}

Stack CreateStack()
{
    Stack S = (Stack)malloc(sizeof(struct Node));
    if(S == NULL)
        FatalError("Out of space!!!");

    S->Next = NULL;
    MakeEmpty(S);
    return S;
}

void DisposeStack(Stack S)
{
    MakeEmpty(S);
    free(S);
}

void MakeEmpty(Stack S)
{
    if(S == NULL)
        Error("Must use CreateStack first");
    else
        while(!IsEmpty(S))
            Pop(S);
}

void Push(ElementType X, Stack S)
{
    PtrToNode Temp = (PtrToNode)malloc(sizeof(struct Node));
    if(Temp == NULL)
        FatalError("Out of space!!!");
    else
    {
        Temp->Element = X;
        Temp->Next = S->Next;
        S->Next = Temp;
    }
}

ElementType Top(Stack S)
{
    if(!IsEmpty(S))
        return S->Next->Element;
    Error("Empty stack");
    return 0;
}

void Pop(Stack S)
{
    if(IsEmpty(S))
        Error("Empty stack");
    else
    {
        PtrToNode Temp = S->Next;
        S->Next = Temp->Next;
        free(Temp);
    }
}

void PrintStack(Stack S)
{
    if(S == NULL)
        return;
    
    PtrToNode Temp = S->Next;
    while(Temp != NULL)
    {
        printf("%d ", Temp->Element);
        Temp = Temp->Next;
    }
    printf("\n");
}