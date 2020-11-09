//2020年11月3日 21:27:27
//测试分离链接散列表

#include <stdio.h>
#include "hashSep.h"

int main()
{
    HashTable H = InitializeTable(10);
    printf("HashTable Size: %d\n", GetHashTableSize(H));
    Insert(1, H);
    Insert(3, H);
    Insert(5, H);
    Insert(7, H);
    Insert(9, H);
    Insert(9, H);
    Insert(12, H);
    Insert(14, H);
    PrintHashTable(H);

    Delete(3, H);
    Delete(12, H);
    PrintHashTable(H);

    Insert(3, H);
    PrintHashTable(H);

    DestroyTable(H);
    return 0;
}