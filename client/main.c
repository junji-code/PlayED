#include <stdio.h>
#include <stdlib.h>
#include "../include/Musica.h"
#include <string.h>

char* lerarq(FILE* arq){
    char linha[1000], *aux;
    aux = fgets(linha, 1000, arq);
    if(aux){
        return strdup(linha);
    }
    return NULL;
}

int main(){
    FILE* arq = fopen("../Entrada/Entrada/metal.txt", "r");
    if(!arq){
        printf("deu errado\n");
        exit(1);
    }
    char* linha;
    int i = 0;

    musicaSent* koe = InitMusica();
    while( linha = lerarq(arq)){
        i++;
        AddMusica(koe, linha);
        if(i>20 || linha == NULL){
            break;
        }
    }

    ImprimeMusicas(koe);




return 0;
}