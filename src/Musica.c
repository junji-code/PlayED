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


void ImprimeMusicas(void* x){
    tMusica* p = (tMusica*) x;
    printf("%s////%s//\n", p->banda, p->nome);
}

int cmpMusica(tMusica* music1, tMusica* music2){
    int aux;

    if(strcmp(music1->banda, music2->banda) == 0){
        if(strcmp(music1->nome, music2->nome) == 0){
            return 1;
        }
    }
    return 0;
}

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

void AddMusica(void* lista, char* linha){
    if(lista == NULL || linha == NULL){
        return;
    }
    

    tMusica* new = SeparaMusica(linha);

    
}

void destroyMusica(void* x){
    tMusica* p;
    p = (tMusica*) x;

    if(p != NULL){
        free(p->banda);
        free(p->nome);
    }
}