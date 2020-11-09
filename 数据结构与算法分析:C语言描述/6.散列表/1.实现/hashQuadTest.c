//2020年11月5日 10:17:03
//测试开放定址散列表

#include <stdio.h>
#include "hashQuad.h"

int main()
{
    HashTable H = InitializeTable(10);
    printf("HashTable Size: %d\n", GetHashTableSize(H));
    Insert(1, &H);
    Insert(3, &H);
    Insert(5, &H);
    Insert(7, &H);
    Insert(9, &H);
    Insert(12, &H);
    PrintHashTable(H);
    Insert(14, &H);
    PrintHashTable(H);
    Insert(25, &H);
    PrintHashTable(H);

    DestroyTable(H);
    return 0;
}