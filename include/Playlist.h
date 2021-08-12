#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "../include/Lista.h"


void ImprimePlaylist(void *lista);

tList *InitPlaylist();

//NomeArq tem que ter a extensão, .Extensão(Ex: .txt)
void CarregaPlaylist(tList *lista, char *NomeArq);

void addPlaylist(tList* lista, char *nome, void *musica);

void pushMusica(void *playlist, void *musica);

void DestroyPlaylist(void *playlist);

void *removePrimMusica(void *playlist);

int cmpNomePlaylist(void *play1, void *banda);

char *retornaNomePlaylist(void* play);

void imprimeNomePlaylistArq(void* play, void * file);

void ImprimePlayPasta(void* play, void* dir);

int cmpPlayAmigos(void* play1, void* list);

int cmpPlaylist(void* play1, void* play2);

#endif //PLAYLIST_H