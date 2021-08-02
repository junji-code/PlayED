#include <stdio.h>
#include <stdlib.h>
#include "../include/Musica.h"
#include "../include/Lista.h"
#include <string.h>


int main(){
    tList* Musicas = LeArquivoMusicas("../Entrada/Entrada/acoustic-hits.txt");
    char aux[] = "Alicia Keys - No One - Acoustic";

    PrintList(Musicas, ImprimeMusica);
    printf("\n\n");

    SearchList(Musicas, aux, cmpMusica);
    PrintList(Musicas, ImprimeMusica);
    printf("\n\n");

    void* koe;
    koe = SearchRemoveList(Musicas, aux, cmpMusica);
    ImprimeMusica(koe);
    printf("\n\n");
    
    destroyMusica(koe);
    free(koe);
    PrintList(Musicas, ImprimeMusica);
    DestroyList(Musicas);



return 0;
}