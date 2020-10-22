#include <stdio.h>
#include "list.h"

struct Node
{
    ElementType Element;
    Position Next;
};

List MakeEmpty(List L)
{
    if (L != NULL)
        DeleteList(L);
    
    L = (List)malloc(sizeof(struct Node));
    if (L == NULL)
        FatalError("Out of space");
    
    L->Next = NULL;
    return L;
}

int IsEmpty(List L)
{
    return L->Next == NULL;
}

int IsLast(Position P, List L)
{
    return P->Next == NULL;
}

Position Find(ElementType X, List L)
{
    Position P = L->Next;
    while(P != NULL && P->Element != X)
        P = P->Next;

    return P;
}

void Delete(ElementType X, List L)
{
    Position P = FindPrevious(X, L);
    if (!IsLast(P, L))
    {
        Position Temp = P->Next;
        P->Next = Temp->Next;
        free(Temp);
    }
}

Position FindPrevious(ElementType X, List L)
{
    Position P = L;
    while(P->Next != NULL && P->Next->Element != X)
        P = P->Next;
    
    return P;
}

void Insert(ElementType X, List L, Position P)
{
    Position Temp = (Position)malloc(sizeof(struct Node));
    if(Temp == NULL)
        FatalError("Out of space!!!");
    
    Temp->Element = X;
    Temp->Next = P->Next;
    P->Next = Temp;
}

void DeleteList(List L)
{
    Position P, Temp;
    P = L->Next;
    L->Next = NULL;
    while(P != NULL)
    {
        Temp = P->Next;
        free(Temp);
        P = Temp;
    }
}

Position Header(List L)
{
    return L;
}

Position First(List L)
{
    return L->Next;
}

Position Advance(Position P)
{
    return P->Next;
}

ElementType Retrieve(Position P)
{
    return P->Element;
}

void PrintList(List L)
{
    if (L == NULL)
        return;
    
    Position P = L->Next;
    while (P != NULL)
    {
        printf("%d ", P->Element);
        P = P->Next;
    }
    printf("\n");
}