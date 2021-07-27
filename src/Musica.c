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

void ImprimeMusicas(musicaSent* lista){
    tMusica* p;
    for(p = lista->prim; p !=NULL; p = p->prox){
        printf("%s////%s//\n", p->banda, p->nome);
    }
}

//somente aqui
int cmpMusica(tMusica* music1, tMusica* music2){
    int aux;

    if(strcmp(music1->banda, music2->banda) == 0){
        if(strcmp(music1->nome, music2->nome) == 0){
            return 1;
        }
    }
    return 0;
}

//somente aqui
tMusica* SeparaMusica(char* linha){
    tMusica* new = malloc(sizeof(tMusica));
    char* aux;

    aux = strtok(linha, "-");
    aux[strlen(aux) - 1] = '\0'; 
    new->banda = strdup(aux);

    aux = strtok(NULL, "\n");
    sscanf(aux, " %[^\n]", aux);//tirar o espaco depois do '-'
    new->nome = strdup(aux);

    new->prox = NULL;

    return new;
}

musicaSent* InitMusica(){
    musicaSent* new = malloc(sizeof(musicaSent));
    new->prim = NULL;
    new->ult = NULL;
    return new;
}

void AddMusica(musicaSent* lista, char* linha){
    if(lista == NULL || linha == NULL){
        return;
    }

    tMusica* new = SeparaMusica(linha);

    if(!lista->prim){
        lista->prim = new;
    }
    if(lista->ult){
        lista->ult->prox = new;
    }
    lista->ult = new;
}

char* RemoveMusica(musicaSent* lista, char* musica){
    if(lista == NULL || musica == NULL){
        return NULL;
    }

    tMusica* preocura = SeparaMusica(musica);
    tMusica* p, *ant = NULL;

    for(p = lista->prim; p != NULL; p = p->prox){
        if(cmpMusica(p, preocura)){
            break;
        }
        ant = p;
    }

    if(p == NULL){
        return NULL;
    }

    if(ant == NULL){
        lista->prim == p->prox;
    }
    else{
        ant->prox = p->prox;
    }

    //soma o '\0' e " - "
    int tam = strlen(p->banda) + strlen(p->nome) + 4;
    char* retirada = malloc(sizeof(char) * tam);
    sprintf(retirada, "%s - %s", p->banda, p->nome);
    
    free(p->banda);
    free(p->nome);
    free(p);

    return retirada;
}

void destroyMusica(musicaSent* lista){
    tMusica* p, *aux;
    p = lista->prim;

    while(p != NULL){
        aux = p;
        p = p->prox;
        free(aux->banda);
        free(aux->nome);
        free(aux);
    }

    free(lista);
}