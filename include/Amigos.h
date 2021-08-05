#ifndef AMIGOS_H
#define AMIGOS_H

typedef struct amigos Amigos;

Amigos *initAmigos(void *usuario);

void *retornaUsuario(Amigos *amigos);

void destroyAmigos(Amigos *amigos);

#endif