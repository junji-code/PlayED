#ifndef MUSICA_H
#define MUSICA_H

#include "../include/Lista.h"

tList* LeArquivoMusicas(char* NomeArq);

void* cmpMusica(void* x, void* y);

void ImprimeMusica(void* x);

void destroyMusica(void* x);

#endif//MUSICA_H
