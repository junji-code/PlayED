#ifndef FILES_H
#define FILES_H

#include <stdio.h>

FILE* OpenFileIn(char *NomeArq, char *mode);

FILE* OpenFileOut(char *NomeArq, char *mode);

void CreateOutDir(char *nome);

#endif//FILES_H