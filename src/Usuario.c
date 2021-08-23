#include "Usuario.h"
#include "Lista.h"
#include "Playlist.h"
#include "Amigos.h"
#include "Musica.h"
#include "../include/Aplicacao.h"
#include "../include/Files.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

#define ARQPLAYLISTS "playlists.txt"
#define ARQREFATORADA "played-refatorada.txt"
#define ARQSIMILARIDADES "similaridades.txt"

struct usuario
{
    //String do nome do usuário
    char *nome;
    //Ponteiro para lista de amigos
    tList *amigos;
    //Ponteiro para lista de playlists
    tList *playlist;
    //Número de playlists do usuário
    int nPlaylist;
};

int comparaNome(void *usu, void *nom)
{
    Usuario *usuario = (Usuario *)usu;
    char *nome = (char *)nom;
    if (usuario != NULL)
    {
        if (nome != NULL)
        {
            if (strcmp(usuario->nome, nome) == 0)
            {
                return 1;
            }
            else
                return 0;
        }
        else
        {
            printf("Nome nulo na busca do usuário!\n");
            exit(1);
        }
    }
    else
    {
        printf("Usuario nulo na busca do nome!\n");
        exit(1);
    }
}

void destroyUsuario(void *usuario)
{
    Usuario *aux = (Usuario *)usuario;

    if (aux != NULL)
    {
        if (aux->nome != NULL)
            free(aux->nome);
        if (aux->amigos != NULL)
            DestroyList(aux->amigos);
        if (aux->playlist != NULL)
            DestroyList(aux->playlist);
    }
}

tList *inicializaUsuarios(char *arq)
{
    tList *listaUsuarios = NewList(sizeof(Usuario), destroyUsuario);

    FILE *parq = OpenFileIn(arq, "r");
    

    char *linha = (char *)calloc(200, sizeof(char));
    fgets(linha, 200, parq);
    char *nome = strtok(linha, ";\n");
    Usuario *usuario = malloc(sizeof(Usuario));
    while (nome != NULL)
    {
        usuario->nome = strdup(nome);
        usuario->playlist = InitPlaylist();
        usuario->amigos = NewList(sizeof(Usuario *), NULL);
        usuario->nPlaylist = 0;
        addEnd(listaUsuarios, usuario);

        nome = strtok(NULL, ";\n");
    }

    //lista de amigos
    Usuario *usuario1 = NULL;
    Amigos *amigo1 = NULL;
    Amigos *amigo2 = NULL;
    Usuario *usuario2 = NULL;
    while (fgets(linha, 200, parq) != NULL)
    {
        //busca primeiro usuario
        nome = strtok(linha, ";");
        usuario1 = (Usuario *)SearchList(listaUsuarios, nome, comparaNome);
        amigo1 = initAmigos(usuario1);
        //busca segundo usuario
        nome = strtok(NULL, "\n");
        usuario2 = (Usuario *)SearchList(listaUsuarios, nome, comparaNome);
        amigo2 = initAmigos(usuario2);
        if (usuario1 != NULL && usuario2 != NULL)
        {
            //adiciona usuario2 na lista de amigos do usuario 1
            addEnd(usuario1->amigos, amigo2);
            //adiciona usuario1 na lista de amigos do usuario 2
            addEnd(usuario2->amigos, amigo1);
        }
        else
            printf("Usuário não encontrado!\n");

        destroyAmigos(amigo1);
        destroyAmigos(amigo2);
    }

    inserePlaylists(listaUsuarios, ARQPLAYLISTS);

    free(linha);
    free(usuario);
    fclose(parq);
    return listaUsuarios;
}

void imprimeNome(void *amigo)
{
    Amigos *y = (Amigos *)amigo;
    Usuario *x = (Usuario *)retornaUsuario(y);
    printf("\t%s\n", x[0].nome);
}

void imprimeAmigos(void *amigos)
{
    Usuario *x = (Usuario *)amigos;
    printf("%s qtdplaylist = %d\n", x->nome, x->nPlaylist);
    genericFunctionList(x->amigos, imprimeNome);
    genericFunctionList(x->playlist, ImprimePlaylist);
}

void inserePlaylists(tList *usuarios, char *nomeArq)
{
    FILE *parq = OpenFileIn(nomeArq, "r");

    char *linha = (char *)calloc(200, sizeof(char));
    char *string;
    int n = 0;
    Usuario *usuario = NULL;
    //O tam é usada para saber a posição na string para passar pro strtok
    //pois como usamos ele em uma função dentro de carrega playlist ela 
    //perde a referencia anterior
    int tam = 0;
    while (fgets(linha, 200, parq) != NULL)
    {
        string = strtok(linha, ";");
        tam = strlen(string) + 1;
        usuario = (Usuario *)SearchList(usuarios, string, comparaNome);

        string = strtok(NULL, ";");
        tam += strlen(string) + 1;
        n = atoi(string);

        char *aux = NULL;
        for (int i = 0; i < n; i++)
        {
            aux = linha + tam;
            string = strdup(strtok(aux, ";\n"));
            CarregaPlaylist(usuario->playlist, string);
            tam += strlen(string) + 1;
            free(string);
        }
    }

    free(linha);
    fclose(parq);
}

void refatoraPlaylists(void *pusuario)
{
    Usuario *usuario = (Usuario *)pusuario;
    usuario->nPlaylist = 0;
    tList *refatorada = InitPlaylist();
    tList *retornada = NULL;
    void *musica = NULL;
    char *banda = NULL;

    //playlist retirada da lista do usuario
    void *playlist = removeReturnBase(usuario->playlist);
    while (playlist != NULL)
    {

        //remove a primeira musica da playlist retirada
        musica = removePrimMusica(playlist);
        while (musica != NULL)
        {
            banda = retornaBanda(musica);
            retornada = (tList *)SearchList(refatorada, banda, cmpNomePlaylist);
            //playlist da banda já existe
            if (retornada != NULL)
            {
                pushMusica(retornada, musica);
            }
            else
            {
                addPlaylist(refatorada, banda, musica);
                usuario->nPlaylist++;
            }
            free(musica);
            //final*/
            musica = removePrimMusica(playlist);

        }
        DestroyPlaylist(playlist);
        free(playlist);
        //final
        playlist = removeReturnBase(usuario->playlist);
    }
    DestroyList(usuario->playlist);
    usuario->playlist = refatorada;
}

void ImprimeArqRefatorada(void *pusuario)
{
    Usuario *usuario = (Usuario *)pusuario;
    char nomeArq[] = ARQREFATORADA;
    
    FILE *arq = OpenFileOut(nomeArq, "a");


    fseek(arq, sizeof(char) * (-1), SEEK_END);

    fprintf(arq, "%s;%d;", usuario->nome, usuario->nPlaylist);

    genericFunction2List(usuario->playlist, arq, imprimeNomePlaylistArq);

    fclose(arq);
    arq = OpenFileOut(nomeArq, "r+");
    fseek(arq, -sizeof(char), SEEK_END);
    fputs("\n", arq);

    fclose(arq);

    CreateOutDir(usuario->nome);

    genericFunction2List(usuario->playlist, usuario->nome, ImprimePlayPasta);

}

void Similaridade(tList *usuarios, char *arqAmizades)
{
    Usuario *usuario1, *usuario2;

    FILE *arq = OpenFileIn(arqAmizades, "r");
    
    FILE *simi = OpenFileOut(ARQSIMILARIDADES, "w");
    

    char *linha = malloc(sizeof(char) * 200);
    char *aux;
    int qtd;

    //ignora a primeira linha do arquivo
    fgets(linha, 200, arq);

    while (fgets(linha, 200, arq) != NULL)
    {
        aux = strtok(linha, ";");
        usuario1 = SearchList(usuarios, aux, comparaNome);
        aux = strtok(NULL, "\n");
        usuario2 = SearchList(usuarios, aux, comparaNome);

        if (usuario1 == NULL || usuario2 == NULL)
        {
            printf("usuario nao encontrado\n");
        }
        else{
            qtd = Counter(usuario1->playlist, usuario2->playlist, cmpPlayAmigos);
            //printa no arquivo
            fprintf(simi, "%s;%s;%d\n", usuario1->nome, usuario2->nome, qtd);
        }
    }

    free(linha);
    fclose(simi);
    fclose(arq);
}