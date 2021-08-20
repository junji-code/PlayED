#include "../include/Lista.h"
#include "../include/Files.h"
#include "../include/Usuario.h"
#include <sys/types.h>
#include <sys/stat.h>

void IniciaAplicacao()
{
    tList *usuarios = inicializaUsuarios("amizade.txt");

    //cria o diretorio de saida
    CreateOutDir("");

    genericFunctionList(usuarios, refatoraPlaylists);

    //Reseta o arquivo played-refatorada se existir
    FILE *arq = OpenFileOut("played-refatorada.txt", "w");
    fclose(arq);

    genericFunctionList(usuarios, ImprimeArqRefatorada);

    Similaridade(usuarios, "amizade.txt");

    DestroyList(usuarios);
}