#include "../include/Lista.h"
#include "../include/Amigos.h"
#include "../include/Musica.h"
#include "../include/Playlist.h"
#include "../include/Usuario.h"

void IniciaAplicacao(){
    tList *usuarios = inicializaUsuarios("data/Entrada/amizade.txt");

    //genericFunctionList(usuarios, imprimeAmigos);

    genericFunctionList(usuarios, refatoraPlaylists);

    FILE* arq = fopen("data/Saida/played-refatorada.txt", "w");
    fclose(arq);

    genericFunctionList(usuarios, ImprimeArqRefatorada);

    Similaridade(usuarios, "data/Entrada/amizade.txt");

    DestroyList(usuarios);
}