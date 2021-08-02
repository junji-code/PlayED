#include "Usuario.h"
#include "Lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct usuario
{
    char *nome;
    tList *amigos;
    tList *playlist;
};

void *comparaNome(void *usu, void *nom)
{
    Usuario *usuario = (Usuario *)usu;
    char *nome = (char *)nom;
    if (usuario != NULL)
    {
        if (nome != NULL)
        {
            if (strcmp(usuario->nome, nome) == 0)
            {
                return usuario;
            }
            else
                return NULL;
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
        free(aux);
    }
}

//Lembrar de apagar
Usuario *alocaUsuario()
{
    Usuario *usuario = (Usuario *)malloc(sizeof(Usuario));
    usuario->nome = NULL;
    usuario->amigos = NewList(sizeof(Usuario *), NULL);
    usuario->playlist = NULL;
    return usuario;
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
        //Inicializar playlist
        usuario->amigos = NewList(sizeof(Usuario *), NULL);
        addEnd(listaUsuarios, usuario);

        nome = strtok(NULL, ";\n");
    }

    //lista de amigos
    Usuario *usuario1 = NULL;
    Usuario *usuario2 = NULL;
    while (fgets(linha, 200, parq) != NULL)
    {
        //busca primeiro usuario
        nome = strtok(linha, ";");
        usuario1 = (Usuario *)SearchList(listaUsuarios, nome, comparaNome);
        //busca segundo usuario
        nome = strtok(NULL, "\n");
        usuario2 = (Usuario *)SearchList(listaUsuarios, nome, comparaNome);
        //adiciona usuario2 na lista de amigos do usuario 1
        addEnd(usuario1->amigos, &usuario2);
        //adiciona usuario1 na lista de amigos do usuario 2
        addEnd(usuario2->amigos, &usuario1);
    }

    free(usuario);
    fclose(parq);
    return listaUsuarios;
}

void imprimeNome(void **usuario)
{
    Usuario *x = (Usuario *)(*usuario);
    printf("\t%s\n", x[0].nome);
}

void imprimeAmigos(void *amigos)
{
    Usuario *x = (Usuario *)amigos;
    printf("%s\n", x->nome);
    PrintList(x->amigos, imprimeNome);
}