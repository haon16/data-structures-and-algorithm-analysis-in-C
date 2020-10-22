#include <stdio.h>
#include "list.h"

struct Node
{
    ElementType Element;
    Position Next;
};

List MakeEmpty(List L);

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
    if (P != NULL)
    {
        Position Temp = P->Next;
        P->Next = Temp->Next;
        free(Temp);
    }
}

Position FindPrevious(ElementType X, List L);

void Insert(ElementType X, List L, Position P);

void DeleteList(List L);

Position Header(List L);

Position First(List L);

Position Advance(Position P);

ElementType Retrieve(Position P);