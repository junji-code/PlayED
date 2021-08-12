#include "../include/Lista.h"
#include "../include/Amigos.h"
#include "../include/Musica.h"
#include "../include/Playlist.h"
#include "../include/Usuario.h"
#include <sys/types.h>
#include <sys/stat.h>

void IniciaAplicacao()
{
    tList *usuarios = inicializaUsuarios("data/Entrada/amizade.txt");

    genericFunctionList(usuarios, refatoraPlaylists);

    mkdir("data/Saida", 0777);

    FILE *arq = fopen("data/Saida/played-refatorada.txt", "w");
    if (arq == NULL)
    {
        printf("Não foi possível encontrar o arquivo da refatorada\n");
        exit(1);
    }
    fclose(arq);

    genericFunctionList(usuarios, ImprimeArqRefatorada);

    Similaridade(usuarios, "data/Entrada/amizade.txt");

    DestroyList(usuarios);
}