#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stringFunctions.h"
#include "preProcess.h"

int main()
{

    FILE *arq;
    char linha[200];
    int lines = 0;

    arq = fopen(".//programTeste//teste1.asm","r");
    fgets(linha,200,arq);
    ifDirective(arq,linha,&lines);

    printf("%d\n",lines);
    return 0;
}
