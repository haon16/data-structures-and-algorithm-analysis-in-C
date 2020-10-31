//2020年10月26日 21:14:14
//测试数组实现的队列

#include "arrayQueue.h"

int main()
{
    Queue Q = CreateQueue(7);
    //PrintQueue(Q);

    Enqueue(1, Q);
    Enqueue(3, Q);
    Enqueue(5, Q);
    Enqueue(7, Q);
    Enqueue(9, Q);
    Enqueue(9, Q);
    Enqueue(9, Q);
    PrintQueue(Q);

    Dequeue(Q);
    Dequeue(Q);
    Dequeue(Q);
    Dequeue(Q);
    Dequeue(Q);
    Dequeue(Q);
    PrintQueue(Q);
    printf("%d\n", FrontAndDequeue(Q));
    Dequeue(Q);

    DisposeQueue(Q);
    return 0;
}