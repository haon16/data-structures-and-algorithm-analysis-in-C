//2020年11月4日 11:10:15
//开放定址散列表的实现

#include <stdio.h>
#include <stdlib.h>
#include "hashQuad.h"

#define MinTableSize 10

enum KindOfEntry 
{
    Legitimate,     //合法
    Empty, 
    Deleted
};

struct HashEntry
{
    ElementType Element;
    enum KindOfEntry Info;
};
typedef struct HashEntry Cell;

struct HashTbl
{
    int TableSize;
    Cell *TheCells;
};

Index Hash(ElementType Key, int TableSize)
{
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
    H->TheCells = (Cell*)malloc(sizeof(Cell) * H->TableSize);
    if(H->TheCells == NULL)
        FatalError("Out of space!!!");

    for(int i = 0; i < H->TableSize; i++)
        H->TheCells[i].Info = Empty;

    return H;
}

void DestroyTable(HashTable H)
{
    if(H != NULL)
    {
        free(H->TheCells);
        free(H);
    }
}

Position Find(ElementType Key, HashTable H)
{
    int CollisionNum = 0;
    Position CurrentPos = Hash(Key, H->TableSize);
    while(H->TheCells[CurrentPos].Info != Empty && H->TheCells[CurrentPos].Element != Key)
    {
        //平方探测的快速方法：F(i) = F(i-1) + 2i -1 
        CurrentPos += 2 * ++CollisionNum - 1;       //下一个要探测的单元
        if(CurrentPos >= H->TableSize)
            CurrentPos -= H->TableSize;
    }
    
    return CurrentPos;
}

void Insert(ElementType Key, HashTable *H)
{
    Position Pos = Find(Key, *H);
    if((*H)->TheCells[Pos].Info != Legitimate)
    {
        (*H)->TheCells[Pos].Info = Legitimate;
        (*H)->TheCells[Pos].Element = Key;
    }

    //元素装填率大于60时再散列
    if(GetElementRate(*H) > 60)
        *H = Rehash(*H);
}

ElementType Retrieve(Position P, HashTable H)
{
    if(H != NULL)
        return H->TheCells[P].Element;
    
    return -1;
}

HashTable Rehash(HashTable H)
{
    int OldSize = H->TableSize;
    Cell *OldCells = H->TheCells;

    H = InitializeTable(2 * OldSize);
    for(int i = 0; i < OldSize; i++)
        if(OldCells[i].Info == Legitimate)
            Insert(OldCells[i].Element, &H);

    free(OldCells);
    return H;
}

int GetElementRate(HashTable H)
{
    if(H == NULL)
        return -1;
    
    int Num = 0;
    for(int i = 0; i < H->TableSize; i++)
    {
        if(H->TheCells[i].Info == Legitimate)
            Num++;
    }
    return Num * 100 / H->TableSize;
}

int GetHashTableSize(HashTable H)
{
    return H->TableSize;
}

void PrintHashTable(HashTable H)
{
    if (H == NULL)
        Error("HashTable H == NULL");

    for(int i = 0; i < H->TableSize; i++)
    {
        printf("%d => ", i);
        if(H->TheCells[i].Info == Legitimate)
        {
            printf("%d ", H->TheCells[i].Element);
        }
        printf("\n");
    }
    printf("\n");
}