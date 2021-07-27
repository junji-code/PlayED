#include <stdio.h>
#include <stdlib.h>
#include "../include/Musica.h"
#include <string.h>


int main(){
    FILE* arq = fopen("../Entrada/Entrada/heavymetal.txt", "r");
    if(!arq){
        printf("deu errado\n");
        exit(1);
    }

    char* linha = malloc(sizeof(char) * 1000);

    musicaSent* koe = InitMusica();
    while(fgets(linha, 1000, arq)){
        AddMusica(koe, linha);
    }
    free(linha);

    ImprimeMusicas(koe);

    char musica[] = "Metallica - Sad But True";
    char* aux = RemoveMusica(koe, musica);
    printf("%s\n\n\n", aux);

    ImprimeMusicas(koe);

    destroyMusica(koe);
    fclose(arq);


return 0;
}