#include <stdio.h>
#include <stdlib.h>
#include "../include/Musica.h"
#include "../include/Playlist.h"
#include "../include/Lista.h"
#include "../include/Files.h"
#include "../include/Aplicacao.h"
#include <string.h>

typedef struct Musica tMusica;

struct Musica
{
    char *nome;
    char *banda;
};

char *retornaBanda(void *musica)
{
    tMusica *aux = (tMusica *)musica;
    return aux->banda;
}

void SeparaMusica(tMusica *musica, char *linha)
{
    char *aux;

    aux = strtok(linha, "-");
    aux[strlen(aux) - 1] = '\0';
    musica->banda = strdup(aux);

    aux = strtok(NULL, "\n"); 
    musica->nome = strdup(aux + 1);//tirar o espaco depois do '-'
}

tList *LeArquivoMusicas(char *NomeArq)
{
    FILE *arq = OpenFileIn(NomeArq, "r");
    
    char *linha = malloc(sizeof(char) * 200);
    tMusica *musica = malloc(sizeof(tMusica));
    tList *NewMusicas = NewList(sizeof(tMusica), destroyMusica);

    while (fgets(linha, sizeof(char) * 200, arq) != NULL)
    {
        SeparaMusica(musica, linha);
        addEnd(NewMusicas, musica);
    }

    free(musica);
    free(linha);
    fclose(arq);

    return NewMusicas;
}

tList *InitiMusica(){
    return NewList(sizeof(tMusica), destroyMusica);
}

void ImprimeMusica(void *x)
{
    tMusica *p = (tMusica *)x;
    printf("\t%s - %s\n", p->banda, p->nome);
}

int cmpMusica(void *x, void *y)
{
    tMusica *music1 = (tMusica *)x;
    tMusica *music2 = (tMusica *)y;


    if (strcmp(music1->nome, music2->nome) == 0){
        return 1;
    }

    return 0;
}

void destroyMusica(void *x)
{
    tMusica *p;
    p = (tMusica *)x;

    if (p != NULL)
    {
        free(p->banda);
        free(p->nome);
    }
}

void ImprimeMusicaArq(void *x, void *y){
    tMusica* musica = (tMusica *) x;
    FILE* arq = (FILE *) y;

    fprintf(arq, "%s - %s\n", musica->banda, musica->nome);
}

int cmpListMusica(void* musica, void* list){
    tMusica* music = (tMusica *) musica;
    tList* lista = (tList *) list;
    int qtd = 0;

    qtd = Counter(lista, music, cmpMusica);

    return qtd;
}