#include <stdio.h>
#include <stdlib.h>
#include "../include/Playlist.h"
#include "../include/Musica.h"
#include "../include/Lista.h"
#include <string.h>

typedef struct Playlist tPlaylist;

struct Playlist{
    char* Nome;
    tList* Musicas;
};

void ImpreimePlaylist(void* lista){
    tPlaylist* x = (tPlaylist*) lista;
    printf("%s:\n", x->Nome);
    PrintList(x->Musicas, ImprimeMusica);
    printf("\n");
}

tList* InitPlaylist(){
    tList* Playlist = NewList(sizeof(tPlaylist), DestroyPlaylist);
    return Playlist;
}

void addPlaylist(tList* lista, char* NomeArq){
    tPlaylist* new = malloc(sizeof(tPlaylist));
    new->Nome = strdup(NomeArq);
    new->Musicas = LeArquivoMusicas(new->Nome);
    addEnd(lista, new);
    free(new);
}

void DestroyPlaylist(void* playlist){
    tPlaylist* p = (tPlaylist*) playlist;
    free(p->Nome);
    DestroyList(p->Musicas);
}