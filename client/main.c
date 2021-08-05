#include "../include/Lista.h"
#include "../include/Usuario.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    tList *usuarios = inicializaUsuarios("Entrada/amizade.txt");

    genericFunctionList(usuarios, imprimeAmigos);

    return 0;
}