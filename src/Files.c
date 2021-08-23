#include "../include/Files.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

#define DIRENTRADA "data/Entrada/"
#define DIRSAIDA "data/Saida/"

FILE* OpenFileIn(char *NomeArq, char *mode){
    char *aux = malloc(sizeof(char) * (strlen(DIRENTRADA) + strlen(NomeArq) + 1));
    strcpy(aux, DIRENTRADA);
    strcat(aux, NomeArq);

    FILE* arq = fopen(aux, mode);

    if(!arq){
        printf("Arquivo %s não aberto\n", aux);
        exit(1);
    }

    free(aux);

    return arq;
}

FILE* OpenFileOut(char *NomeArq, char *mode){
    char *aux = malloc(sizeof(char) * (strlen(DIRSAIDA) + strlen(NomeArq) + 1));
    strcpy(aux, DIRSAIDA);
    strcat(aux, NomeArq);

    FILE* arq = fopen(aux, mode);

    if(!arq){
        printf("Arquivo %s não aberto\n", aux);
        exit(1);
    }

    free(aux);
    
    return arq;
}

void CreateOutDir(char *nome){
    char *aux = malloc(sizeof(char) * (strlen(DIRSAIDA) + strlen(nome) + 1));
    strcpy(aux, DIRSAIDA);
    strcat(aux, nome);
    mkdir(aux, 0777);

    free(aux);
}