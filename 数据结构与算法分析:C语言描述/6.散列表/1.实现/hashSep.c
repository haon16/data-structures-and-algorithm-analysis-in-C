//2020年11月8日 14:51:13
//分离链接散列表的实现

#include <stdio.h>
#include "hashSep.h"

#define MinTableSize 10

struct ListNode
{
    ElementType Element;
    Position Next;
};
typedef Position List;

struct HashTbl
{
    int TableSize;
    List *TheLists;
};

Index Hash(ElementType Key, int TableSize)
{
    /*
    unsigned int HashVal = 0;                   //如果KEY是字符串
    while(*Key != '\0')
        HashVal = (HashVal << 5) + *Key++;
    return HashVal % TableSize;
    */
    return Key % TableSize;
}

int NextPrime(int Num)
{
    while(1)
    {
        int i = 2;
        for(; i < Num; i++)
        {
            if(Num % i == 0)
                break;
        }
        if(i == Num)
            break;
        else
            Num++;
    }
    return Num;
}

HashTable InitializeTable(int TableSize)
{
    if(TableSize < MinTableSize)
        Error("Table size too small");

    HashTable H = (HashTable)malloc(sizeof(struct HashTbl));
    if(H == NULL)
        FatalError("Out of space!!!");
    
    H->TableSize = NextPrime(TableSize);
    H->TheLists = (List*)malloc(sizeof(List) * H->TableSize);
    if(H->TheLists == NULL)
        FatalError("Out of space!!!");

    for(int i = 0; i < H->TableSize; i++)           //设置表头
    {
        H->TheLists[i] = (List)malloc(sizeof(struct ListNode));
        if(H->TheLists[i] == NULL)
            FatalError("Out of space!!!");
        else
            H->TheLists[i]->Next = NULL;
    }

    return H;
}

void DestroyTable(HashTable H)
{
    if(H == NULL)
        return;
    
    for(int i = 0; i < H->TableSize; i++)
    {
        List L = H->TheLists[i];
        Position P = L->Next;
        while(P != NULL)
        {
            Position Temp = P;
            P = P->Next;
            free(Temp);
        }
    }
    free(H->TheLists);      //一起释放或者跟上面链表分开释放
    free(H);
}

Position Find(ElementType Key, HashTable H)
{
    List L = H->TheLists[Hash(Key, H->TableSize)];
    Position P = L->Next;
    while(P != NULL && P->Element != Key)       //如果是字符串要使用strcmp比较
        P = P->Next;
    
    return P;
}

void Insert(ElementType Key, HashTable H)
{
    Position Pos = Find(Key, H);
    if (Pos == NULL)
    {
        Position NewCell = (Position)malloc(sizeof(struct ListNode));
        if(NewCell == NULL)
            FatalError("Out of space!!!");
        else
        {
            List L = H->TheLists[Hash(Key, H->TableSize)];
            NewCell->Next = L->Next;
            NewCell->Element = Key;         //如果是字符串要使用strcpy
            L->Next = NewCell;
        }
    }
}

void Delete(ElementType Key, HashTable H)
{
    Position P = Find(Key, H);
    if(P == NULL)
        return;
    else
    {
        List L = H->TheLists[Hash(Key, H->TableSize)];
        Position Temp = L; 
        while(Temp->Next != NULL && Temp->Next->Element != Key)
            Temp = Temp->Next;
        Temp->Next = P->Next;
        free(P);
    }
}

ElementType Retrieve(Position P)
{
    return P->Element;
}

int GetHashTableSize(HashTable H)
{
    return H->TableSize;
}

void PrintHashTable(HashTable H)
{
    if (H == NULL)
        Error("HashTable H == NULL");
    
    List L;
    Position P;

    for(int i = 0; i < H->TableSize; i++)
    {
        printf("%d => ", i);
        L = H->TheLists[i];
        P = L->Next;
        while(P != NULL)
        {
            printf("%d ", P->Element);
            P = P->Next;
        }
        printf("\n");
    }
}