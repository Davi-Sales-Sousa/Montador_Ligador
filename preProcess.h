#ifndef PREPROCESS_H
#define PREPROCESS_H

#include <stdio.h>
#include <stdlib.h>
#include "stringFunctions.h"
#include <string.h>

typedef struct
{
    char labelName[200];
    char valor[20];
}EQU;

//-- Funções Utilitárias --
void getEQULabel(char *origLine);
void getEQUValor(char *origLine);
int getEQUDefinition(char *asmFileName, EQU *equTable);
#endif // PREPROCESS_H
