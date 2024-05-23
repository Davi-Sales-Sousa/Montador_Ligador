#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stringFunctions.h"
#include "preProcess.h"

int main()
{
    FILE *arq;
    char linha[200] = "                             B:\t",linha2[200];

    printf("%d\n",isLabelLine(linha));
    return 0;
}
