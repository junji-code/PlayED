#ifndef USUARIO_H
#define USUARIO_H
#include "../include/Lista.h"

/* ADICIONAR AS PLAYLISTS NOS USUARIOS */

typedef struct usuario Usuario;

void destroyUsuario(void *usuario);

void *comparaNome(void *usuario, void *nome);

tList *inicializaUsuarios(char *arq);

static Usuario *alocaUsuario();

void imprimeAmigos(void *amigos);

#endif