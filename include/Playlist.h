#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "../include/Lista.h"

void ImpreimePlaylist(void* lista);

tList* InitPlaylist();

//NomeArq tem que ter a extensão, .Extensão(Ex: .txt)
void addPlaylist(tList* lista, char* NomeArq);

void DestroyPlaylist(void* playlist);

#endif//PLAYLIST_H