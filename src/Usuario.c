#include "Usuario.h"
#include "Lista.h"
#include "Playlist.h"
#include "Amigos.h"
#include "Musica.h"
#include "../include/Aplicacao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

#define ARQPLAYLISTS "playlists.txt"

struct usuario
{
    char *nome;
    tList *amigos;
    tList *playlist;
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

    FILE *parq = fopen(arq, "r");
    if (parq == NULL)
    {
        printf("Arquivo %s nao encontrado.\n", arq);
        exit(1);
    }

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

    char *aux = malloc(sizeof(char) * (strlen(DIRENTRADA) + strlen(ARQPLAYLISTS) + 1));
    strcpy(aux, DIRENTRADA);
    strcat(aux, ARQPLAYLISTS);
    inserePlaylists(listaUsuarios, aux);
    free(aux);

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
    FILE *parq = fopen(nomeArq, "r");
    if (parq == NULL)
    {
        printf("Falha ao abrir %s!\n", nomeArq);
        exit(1);
    }

    char *linha = (char *)calloc(200, sizeof(char));
    char *string;
    int n = 0;
    Usuario *usuario = NULL;
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
    tList *playlist = (tList *)removeReturnBase(usuario->playlist);
    while (playlist != NULL)
    {

        //remove a primeira musica da playlist retirada
        musica = removePrimMusica(playlist);
        while (musica != NULL)
        {
            banda = retornaBanda(musica);
            retornada = (tList *)SearchList(refatorada, banda, cmpNomePlaylist);
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

            free(banda);
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
    char nomeArq[] = "played-refatorada.txt";
    char *aux = malloc(sizeof(char) * (strlen(DIRSAIDA) + strlen(nomeArq) + 1));
    strcpy(aux, DIRSAIDA);
    strcat(aux, nomeArq);
    FILE *arq = fopen(aux, "a");

    if (!arq)
    {
        printf("arquivo %s nao encontrado", aux);
        exit(1);
    }

    fseek(arq, sizeof(char) * (-1), SEEK_END);

    fprintf(arq, "%s;%d;", usuario->nome, usuario->nPlaylist);

    genericFunction2List(usuario->playlist, arq, imprimeNomePlaylistArq);

    fclose(arq);
    arq = fopen(aux, "r+");
    fseek(arq, -sizeof(char), SEEK_END);
    fputs("\n", arq);

    fclose(arq);

    free(aux);

    aux = malloc(sizeof(char) * (strlen(DIRSAIDA) + strlen(usuario->nome) + 1));
    strcpy(aux, DIRSAIDA);
    strcat(aux, usuario->nome);
    mkdir(aux, 0777);

    genericFunction2List(usuario->playlist, aux, ImprimePlayPasta);

    free(aux);
}

void Similaridade(tList *usuarios, char *arqAmizades)
{
    Usuario *usuario1, *usuario2;

    FILE *arq = fopen(arqAmizades, "r");
    if (arq == NULL)
    {
        printf("Arquivo %s nao encontrado.\n", arqAmizades);
        exit(1);
    }
    char *simiAux = (char *)malloc(sizeof(char) * (strlen(DIRSAIDA) + strlen("similaridades.txt") + 1));
    strcpy(simiAux, DIRSAIDA);
    strcat(simiAux, "similaridades.txt");
    FILE *simi = fopen(simiAux, "w");
    if (simi == NULL)
    {
        printf("Arquivo %s nao encontrado.\n", simiAux);
        exit(1);
    }

    char *linha = malloc(sizeof(char) * 200);
    char *aux;
    int qtd;
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
            return;
        }

        qtd = Counter(usuario1->playlist, usuario2->playlist, cmpPlayAmigos);
        //printa no arquivo
        fprintf(simi, "%s;%s;%d\n", usuario1->nome, usuario2->nome, qtd);
    }

    free(linha);
    free(simiAux);
    fclose(simi);
    fclose(arq);
}