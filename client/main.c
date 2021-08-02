#include <stdio.h>
#include <stdlib.h>
#include "../include/Musica.h"
#include "../include/Usuario.h"
#include "../include/Lista.h"
#include <string.h>

int main()
{
    char aux[] = "Entrada/amizade.txt";

    tList *usuarios = inicializaUsuarios(aux);

    PrintList(usuarios, imprimeAmigos);

    return 0;
}