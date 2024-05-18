#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stringFunctions.h"


int main()
{
    FILE *arq;
    char linha[200];
    int i;
    arq = fopen("./programTeste/teste1.asm","r");

    for(;fgets(linha,200,arq) != NULL;)
    {
        removeUselessCharacter(linha);
        printf("%s",linha);
    }

    return 0;
}
