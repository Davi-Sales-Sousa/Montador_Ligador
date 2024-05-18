#include "stringFunctions.h"

//This function remove Comment from orig string
void removeComment(char *origLine)
{
    const int TAM = strlen(origLine);
    int i;

    for(i = 0; i < TAM-1; i++)
    {
        if(origLine[i] == ';')
        {
            origLine[i] = '\n';
            origLine[i+1] = '\0';
            return;
        }

    }
}

//This function check if in the line just have useless character, if yes discard line, if not make nothing
int removeUselessCharacter(char *origLine)
{
    const int TAM = strlen(origLine);
    char auxLine[TAM];
    int i,countUseless = 0;

    strcpy(auxLine,origLine);
    for(i = 0; i < TAM; i++)
    {
        if(auxLine[i] == '\t' || auxLine[i] == '\n' || auxLine[i] == ' ')
            countUseless++;
    }
    if(countUseless == TAM)
    {
        strcpy(origLine,"\0");
        return 1; // if the function return 1 this meaning that the line is useless
    }
    return 0; // if the function return 0 this meaning that the line is useful

}
