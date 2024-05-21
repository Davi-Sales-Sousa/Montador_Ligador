#ifndef STRINGFUNCTIONS_H
#define STRINGFUNCTIONS_H

#include <string.h>
#include <ctype.h>

void removeComment(char *orig);
int removeUselessCharacter(char *origLine);
void stringUppercase(char *origLine);
#endif // STRINGFUNCTIONS_H
