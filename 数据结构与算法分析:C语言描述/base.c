#include <stdio.h>
#include "base.h"

void FatalError(char *msg)
{
    fputs(msg, stdout);
    fputc("\n", stdout);
    exit(1);
}