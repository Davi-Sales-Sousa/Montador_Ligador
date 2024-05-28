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

typedef struct
{
    char token[200];
}preTokens;

//-- Funções Utilitárias --
void getEQULabel(char *origLine);
void getEQUValor(char *origLine);
int getEQUDefinition(char *asmFileName, EQU *equTable);
int isLabelLine(char *origLine);
void skipLines(FILE *arq, int qtdSkipLines,int *currentLine, int choose);
void getIFValor(char *origLine, char *valor);
int isIFDirective(char *origLine);
void ifDirective(FILE *asmFile,char *currentLine, int *lines);
//void getTokkens(char *origLine, preTokens *preTokenList);
//void writeLine(FILE *asmFile);
#endif // PREPROCESS_H
