#include <stdio.h>
#include <stdlib.h>
#include "../include/Playlist.h"
#include "../include/Musica.h"
#include "../include/Lista.h"
#include "../include/Aplicacao.h"
#include <string.h>


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
    char *aux = malloc(sizeof(char) * (strlen(DIRENTRADA) + strlen(NomeArq) + 1));
    strcpy(aux, DIRENTRADA);
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
        destroyMusica(musica);
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
    
    if (strncmp(playlist->Nome, nBanda, tam) == 0)
    {
        return 1;
    }
    return 0;
}

void imprimeNomePlaylistArq(void* play, void * file){
    FILE *arq = (FILE *)file;
    tPlaylist * playlist = (tPlaylist *)play;
    char* aux = strdup(playlist->Nome);
    int tamDIR = strlen(DIRENTRADA);
    fprintf(arq, "%s.txt;", aux + tamDIR);
    free(aux);
}

void ImprimePlayPasta(void* play, void* dir){
    tPlaylist *playlist = (tPlaylist *)play;
    int tamDIR = strlen(DIRENTRADA);
    char* diretorio = (char *) dir;
    //soma mais 6 por causa da / do riretorio, .txt e o \0 do final
    char* pasta = malloc(sizeof(char) * (strlen(diretorio) + strlen(playlist->Nome + tamDIR) + 6));
    strcpy(pasta, diretorio);
    strcat(pasta,"/");
    strcat(pasta, playlist->Nome + tamDIR);
    strcat(pasta,".txt");


    FILE *arq = fopen(pasta, "w");

    if (!arq)
    {
        printf("arquivo %s nao encontrado", pasta);
        exit(1);
    }

    genericFunction2List(playlist->Musicas, arq, ImprimeMusicaArq);


    free(pasta);
    fclose(arq);
}

int cmpPlayAmigos(void* play1, void* list){
    tPlaylist* playlist = (tPlaylist *) play1;
    tList* lista = (tList *) list;
    int qtd = 0;
    qtd = Counter(lista, playlist, cmpPlaylist);

    return qtd;
}

int cmpPlaylist(void* play1, void* play2){
    tPlaylist* playlist1 = (tPlaylist *) play1;
    tPlaylist* playlist2 = (tPlaylist *) play2;
    int qtd = 0;
    

    if(strcmp(playlist1->Nome, playlist2->Nome) == 0){
        qtd = Counter(playlist1->Musicas, playlist2->Musicas, cmpListMusica);    
    }

    return qtd;
}