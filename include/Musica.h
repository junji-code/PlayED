#ifndef MUSICA_H
#define MUSICA_H

#include "../include/Lista.h"

tList *LeArquivoMusicas(char *NomeArq);

char *retornaBanda(void *musica);

void *cmpMusica(void *x, void *y);

void ImprimeMusica(void *x);

void destroyMusica(void *x);

#endif //MUSICA_H
