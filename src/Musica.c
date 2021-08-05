#include <stdio.h>
#include <stdlib.h>
#include "../include/Musica.h"
#include "../include/Lista.h"
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
    sscanf(aux, " %[^\n]", aux); //tirar o espaco depois do '-'
    musica->nome = strdup(aux);
}

tList *LeArquivoMusicas(char *NomeArq)
{
    FILE *arq = fopen(NomeArq, "r");
    if (!arq)
    {
        printf("arquivo %s nao encontrado", NomeArq);
        exit(1);
    }
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

void ImprimeMusica(void *x)
{
    tMusica *p = (tMusica *)x;
    printf("\t%s - %s\n", p->banda, p->nome);
}

void *cmpMusica(void *x, void *y)
{
    tMusica *music1 = (tMusica *)x;
    char *music2 = (char *)y;
    int tam = strlen(music1->banda) + strlen(music1->nome) + 4;
    char *aux = malloc(sizeof(char) * tam);
    sprintf(aux, "%s - %s", music1->banda, music1->nome);

    if (strcmp(aux, music2) == 0)
    {
        free(aux);
        return x;
    }

    free(aux);
    return NULL;
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