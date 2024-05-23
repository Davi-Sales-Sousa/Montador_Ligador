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

//This function analize the origLine and get EQU Valor as string
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

//This function search all EQU definition on the code begin, return the how many lines was jumped
int getEQUDefinition(char *asmFileName, EQU *equTable)
{
    int equNumber = 0; // This is the number of equs that have in the code
    int jumpedLines = 0;
    FILE *asmFile = fopen(asmFileName,"r");
    char line[200],line2[200];
    const int foundAllEQU = 0;

    equTable = (EQU*)malloc(sizeof(EQU));

    while(!foundAllEQU) //while not found all equ at the begin of code continue the search
    {
        fgets(line,200,asmFile);
        jumpedLines++;
        removeComment(line);
        stringUppercase(line);
        strcpy(line2,line);

        //This code block check stop to the loop, if no EQU and no label or comment or blank line, end loop
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

        //Save the equLabel on the equTable
        if(strstr(line2,":") != NULL)
        {
            getEQULabel(line2);
            #if DEBUGAR2
                printf("%s\n",line2);
                ashsihdishdihsaih
            #endif // DEBUGAR
            strcpy(equTable[equNumber].labelName,line2);
        }

        //Save the equValor on the equTable
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

    return jumpedLines - 1;
}

//This function return 1 if the line is LabelLine, ex: 'L1:  ', else return 0 if not LabelLine
int isLabelLine(char *origLine)
{
    char *pos;
    int posDiv; //This variable meaning the pos of the character ':'
    int i,blankLineBegin = 0;
    const int origLineTAM = strlen(origLine);

    pos = strchr(origLine,':');

    posDiv = pos - origLine;

    if((posDiv - 1) < 0 || (origLine[posDiv - 1] == ' ' || origLine[posDiv - 1] == '\t' || origLine[posDiv - 1] == '\n'))
        return 0;//not LabeLine

    for(i = posDiv; i >= 0 ; i--)
    {
        if(origLine[i] == ' ' || origLine[i] == '\t' || origLine[i] == '\n')
        {
            blankLineBegin = i;
            break;
        }
    }

    if(blankLineBegin != 0)
    {
        for(i = blankLineBegin; i >= 0; i--)
        {
            if(!(origLine[i] == ' ' || origLine[i] == '\t' || origLine[i] == '\n'))
            {
                return 0;//not LabeLine
            }
        }
    }

    for(i = posDiv + 1; i < origLineTAM; i++)
    {
        if(!(origLine[i] == ' ' || origLine[i] == '\t' || origLine[i] == '\n'))
        {
            return 0;//not LabeLine
        }
    }

    return 1;//is LabeLine
}

// This function check if is IF directive. if return 1 have IF directive in the line, if 0 don't have IF directive in the line
int isIFDirective(char *origLine)
{
    if(strstr(origLine,"IF") != NULL)
    {
        return 1;//have IF directive in the line
    }
    return 0;// don't have IF directive in the line
}

// This function execute the if directive
void ifDirective(FILE *asmFile,int *lines)
{
    char valor[20];
    int

}
