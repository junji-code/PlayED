#include "../include/Lista.h"
#include "../include/Files.h"
#include "../include/Amigos.h"
#include "../include/Musica.h"
#include "../include/Playlist.h"
#include "../include/Usuario.h"
#include <sys/types.h>
#include <sys/stat.h>

void IniciaAplicacao()
{
    tList *usuarios = inicializaUsuarios("amizade.txt");

    genericFunctionList(usuarios, refatoraPlaylists);

    //genericFunctionList(usuarios, imprimeAmigos);
    
    CreateOutDir("");

    //Reseta o arquivo played-refatorada se existir
    FILE *arq = OpenFileOut("played-refatorada.txt", "w");
    fclose(arq);

    //genericFunctionList(usuarios, imprimeAmigos);
    genericFunctionList(usuarios, ImprimeArqRefatorada);

    Similaridade(usuarios, "amizade.txt");

    DestroyList(usuarios);
}