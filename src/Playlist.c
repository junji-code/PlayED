#include <stdio.h>
#include <stdlib.h>
#include "../include/Playlist.h"
#include "../include/Musica.h"
#include "../include/Lista.h"
#include <string.h>

#define DIR "Entrada/"

//CRIAR UMA QUE REFATORA UMA PLAYLIST

typedef struct Playlist tPlaylist;

struct Playlist
{
    char *Nome;
    tList *Musicas;
};

void *removePrimMusica(void *playlist)
{
    tPlaylist *aux = (tPlaylist *)playlist;
    return removeReturnBase(aux->Musicas);
}

void ImprimePlaylist(void *lista)
{
    tPlaylist *x = (tPlaylist *)lista;
    printf("%s:\n", x->Nome);
    genericFunctionList(x->Musicas, ImprimeMusica);
    printf("\n");
}

tList *InitPlaylist()
{
    tList *Playlist = NewList(sizeof(tPlaylist), DestroyPlaylist);
    return Playlist;
}

void addPlaylist(tList *lista, char *NomeArq)
{
    tPlaylist *new = malloc(sizeof(tPlaylist));
    char *aux = malloc(sizeof(char) * (strlen(DIR) + strlen(NomeArq) + 1));
    strcpy(aux, DIR);
    strcat(aux, NomeArq);
    //new->Nome = strdup(NomeArq);
    new->Nome = aux;
    new->Musicas = LeArquivoMusicas(new->Nome);
    addEnd(lista, new);
    free(new);
}

void DestroyPlaylist(void *playlist)
{
    tPlaylist *p = (tPlaylist *)playlist;
    free(p->Nome);
    DestroyList(p->Musicas);
}

int cmpNomePlaylist(void *play1, void *banda)
{
    tPlaylist *playlist = (tPlaylist *)play1;
    char *nBanda = (char *)banda;
    int tam = strlen(DIR) + strlen(nBanda);
    char *aux = malloc(sizeof(char) * (tam + 1));
    strcpy(aux, DIR);
    strcat(aux, nBanda);

    if (strncmp(playlist->Nome, aux, tam) == 0)
    {
        return 1;
    }
    return 0;
}