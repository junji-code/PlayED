#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "../include/Lista.h"

void ImprimePlaylist(void *lista);

tList *InitPlaylist();

//NomeArq tem que ter a extensão, .Extensão(Ex: .txt)
void addPlaylist(tList *lista, char *NomeArq);

void DestroyPlaylist(void *playlist);

void *removePrimMusica(void *playlist);

int cmpNomePlaylist(void *play1, void *banda);

#endif //PLAYLIST_H