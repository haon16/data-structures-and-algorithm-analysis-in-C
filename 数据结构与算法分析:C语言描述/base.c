#include <stdio.h>
#include <stdlib.h>
#include "base.h"

void FatalError(const char *msg)
{
    fputs(msg, stdout);
    fputc('\n', stdout);
    exit(1);
}

void Error(const char *msg)
{
    FatalError(msg);
}

int Max(int a, int b)
{
    return a > b ? a : b;
}