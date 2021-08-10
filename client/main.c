#include "../include/Lista.h"
#include "../include/Usuario.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    tList *usuarios = inicializaUsuarios("Entrada/amizade.txt");

    //genericFunctionList(usuarios, imprimeAmigos);
    //printf("carregou\n\n");

    genericFunctionList(usuarios, refatoraPlaylists);

    //printf("Refatorada:\n\n");
    //genericFunctionList(usuarios, imprimeAmigos);

    //genericFunctionList(usuarios, ImprimeArqRefatorada);
    
    Similaridade(usuarios, "Entrada/amizade.txt");

    DestroyList(usuarios);


    return 0;
}