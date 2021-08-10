#ifndef MUSICA_H
#define MUSICA_H

#include "../include/Lista.h"

tList *LeArquivoMusicas(char *NomeArq);

tList *InitiMusica();

char *retornaBanda(void *musica);

int cmpMusica(void *x, void *y);

void ImprimeMusica(void *x);

void ImprimeMusicaArq(void *x, void *y);

int cmpListMusica(void* musica, void* list);

void destroyMusica(void *x);

#endif //MUSICA_H