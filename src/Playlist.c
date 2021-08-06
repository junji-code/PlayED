#include <stdio.h>
#include <stdlib.h>
#include "../include/Playlist.h"
#include "../include/Musica.h"
#include "../include/Lista.h"
#include <string.h>


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

void CarregaPlaylist(tList *lista, char *NomeArq)
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

void addPlaylist(tList* lista, char *nome, void *musica){
    tPlaylist* new = malloc(sizeof(tPlaylist));
    new->Nome = strdup(nome);
    new->Musicas = InitiMusica();
    addEnd(new->Musicas, musica);
    addEnd(lista, new);
    free(new);
}

void pushMusica(void *playlist, void *musica){
    tPlaylist *play = (tPlaylist *) playlist;
    if(!SearchList(play->Musicas, musica, cmpMusica)){
        addEnd(play->Musicas, musica);
    }
    else{
        printf("achou: ");
        ImprimeMusica(musica);
    }
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
    int tam = strlen(nBanda);
    // char *aux = malloc(sizeof(char) * (tam + 1));
    // strcpy(aux, DIR);
    // strcat(aux, nBanda);
    //printf("Comparando %s - %s  ", nBanda, playlist->Nome);
    if (strncmp(playlist->Nome, nBanda, tam) == 0)
    {
        //printf("foi\n\n");
        return 1;
    }
    //printf("nao foi\n\n");
    return 0;
}

void imprimeNomePlaylistArq(void* play, void * file){
    FILE *arq = (FILE *)file;
    tPlaylist * playlist = (tPlaylist *)play;
    fprintf(arq, "%s.txt;", playlist->Nome);
}