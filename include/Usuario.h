#ifndef USUARIO_H
#define USUARIO_H
#include "../include/Lista.h"

/* ADICIONAR AS PLAYLISTS NOS USUARIOS */

typedef struct usuario Usuario;

void destroyUsuario(void *usuario);

int comparaNome(void *usu, void *nom);

tList *inicializaUsuarios(char *arq);

void imprimeAmigos(void *amigos);

static void inserePlaylists(tList *usuarios, char *nomeArq);

void refatoraPlaylists(void *pusuario);

void ImprimeArqRefatorada(void *pusuario);

void Similaridade(tList* usuarios, char* arqAmizades);

#endif