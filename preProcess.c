#include "preProcess.h"
#define DEBUGAR 1
#define DEBUGAR2 0
void getEQULabel(char *origLine)
{
    const int origLineTAM = strlen(origLine);
    int i,j = 0;

    for(i = 0; i <= origLineTAM; i++)
    {
        if(!(origLine[i] == '\t' || origLine[i] == '\n' || origLine[i] == ' ' || origLine[i] == ':'))
        {
            origLine[j] = origLine[i];
            j++;
        }
        if(origLine[i] == ':')
            break;
    }
    origLine[j] = '\0';
    #if DEBUGAR2
    printf("%s\n",origLine);
    #endif
}

void getEQUValor(char *origLine)
{
    const int origLineTAM = strlen(origLine);
    int i, j = 0;

    for(i = 0; i < origLineTAM; i++)
    {
        if(origLine[i] >= '0' && origLine[i] <= '9')
        {
            origLine[j] = origLine[i];
            j++;
        }
    }

    origLine[j] = '\0';

    #if DEBUGAR2
        printf("%s\n",origLine);
    #endif // DEBUGAR

}

//This function search all EQU definition on the code begin
int getEQUDefinition(char *asmFileName, EQU *equTable)
{
    int continueReaderLine; //This variable stores the line number that the program will read after processing the equs
    int equNumber = 0; // This is the number of equs that have in the code
    FILE *asmFile = fopen(asmFileName,"r");
    char line[200],line2[200];
    const int foundAllEQU = 0;

    equTable = (EQU*)malloc(sizeof(EQU));

    while(!foundAllEQU)
    {
        fgets(line,200,asmFile);
        removeComment(line);
        strcpy(line2,line);

        if(strstr(line2,"EQU") == NULL)
        {
            if(strchr(line2,':') == NULL)
            {
                char line3[200];
                strcpy(line3,line2);

                if(removeUselessCharacter(line3) == 1)
                    continue;
                else
                    break;
            }
        }

        if(strstr(line2,":") != NULL)
        {
            getEQULabel(line2);
            #if DEBUGAR2
                printf("%s\n",line2);
            #endif // DEBUGAR
            strcpy(equTable[equNumber].labelName,line2);
        }

        if(strstr(line,"EQU") != NULL)
        {
            strcpy(line2,strstr(line,"EQU"));
            getEQUValor(line2);
            strcpy(equTable[equNumber].valor,line2);
            equNumber++;
        }

        equTable = (EQU*)realloc(equTable,(equNumber+1)*sizeof(EQU));


    }

    #if DEBUGAR
    int i;
    for(i = 0; i < equNumber; i++)
        printf("Label: %s Valor: %s\n",equTable[i].labelName,equTable[i].valor);
    #endif // DEBUGAR

    continueReaderLine = equNumber;

    return continueReaderLine;
}
