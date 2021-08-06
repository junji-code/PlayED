#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "../include/Lista.h"

#define DIR "Entrada/"

void ImprimePlaylist(void *lista);

tList *InitPlaylist();

//NomeArq tem que ter a extensão, .Extensão(Ex: .txt)
void CarregaPlaylist(tList *lista, char *NomeArq);

void addPlaylist(tList* lista, char *nome, void *musica);

void pushMusica(void *playlist, void *musica);

void DestroyPlaylist(void *playlist);

void *removePrimMusica(void *playlist);

int cmpNomePlaylist(void *play1, void *banda);

#endif //PLAYLIST_H