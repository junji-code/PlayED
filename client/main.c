#include <stdio.h>
#include <stdlib.h>
#include "../include/Musica.h"
#include "../include/Playlist.h"
#include "../include/Lista.h"
#include <string.h>


int main(){
    tList* playlist = InitPlaylist();
    char arq1[] = "../Entrada/Entrada/heavymetal.txt";
    char arq2[] = "../Entrada/Entrada/acoustic-hits.txt";
    addPlaylist(playlist, arq1);
    addPlaylist(playlist, arq2);

    PrintList(playlist, ImpreimePlaylist);

    DestroyList(playlist);

    // tList* Musicas = LeArquivoMusicas("../Entrada/Entrada/acoustic-hits.txt");
    // char aux[] = "Alicia Keys - No One - Acoustic";

    // PrintList(Musicas, ImprimeMusica);
    // printf("\n\n");

    // SearchList(Musicas, aux, cmpMusica);
    // PrintList(Musicas, ImprimeMusica);
    // printf("\n\n");

    // void* koe;
    // koe = SearchRemoveList(Musicas, aux, cmpMusica);
    // ImprimeMusica(koe);
    // printf("\n\n");
    
    // destroyMusica(koe);
    // free(koe);
    // PrintList(Musicas, ImprimeMusica);
    // DestroyList(Musicas);


return 0;
}