#include <stdio.h>
#include <stdlib.h>
#include "../include/Musica.h"
#include <string.h>

typedef struct Musica tMusica;

struct Musica{
    tMusica* prox;
    char* nome;
    char* banda;
};

struct sMusica{
    tMusica* prim;
    tMusica* ult;
};

musicaSent* InitMusica(){
    musicaSent* new = malloc(sizeof(musicaSent));
    new->prim = NULL;
    new->ult = NULL;
    return new;
}

void AddMusica(musicaSent* lista, char* linha){
    tMusica* new = malloc(sizeof(tMusica));
    char* aux;

    aux = strtok(linha, "-");
    aux[strlen(aux) - 1] = '\0'; 
    new->banda = strdup(aux);

    aux = strtok(NULL, "\n");
    sscanf(aux, " %[^\n]", aux);//tirar o espaco depois do '-'
    new->nome = strdup(aux);

    new->prox = NULL;

    if(!lista->prim){
        lista->prim = new;
    }
    if(lista->ult){
        lista->ult->prox = new;
    }
    lista->ult = new;
}

void ImprimeMusicas(musicaSent* lista){
    tMusica* p;
    for(p = lista->prim; p !=NULL; p = p->prox){
        printf("%s////%s//\n", p->banda, p->nome);
    }
}