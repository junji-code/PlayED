#include "Amigos.h"
#include <stdio.h>
#include <stdlib.h>

struct amigos
{
    void *usuario;
};

Amigos *initAmigos(void *usuario)
{
    Amigos *amigos = (Amigos *)malloc(sizeof(Amigos));
    amigos->usuario = usuario;
    return amigos;
}

void *retornaUsuario(Amigos *amigos)
{
    return amigos->usuario;
}

void destroyAmigos(Amigos *amigos)
{
    free(amigos);
}