#ifndef AMIGOS_H
#define AMIGOS_H

/**
 * @brief TAD de Amigos. Facilita a implementação do TAD usuário.
*/
typedef struct amigos Amigos;

/**
 * @brief Inicializa um amigo e insere um usuário nele.
 * @param *usuario: Ponteiro para o usuário a ser inserido.
 * @pre *usuario aponta para um Usuário.
 * @post Amigo inicializado, e usuário inalterado.
 * @return Ponteiro para o amigo.
*/
Amigos *initAmigos(void *usuario);

/**
 * @brief Retorna o ponteiro do usuário inserido em um amigo.
 * @param *amigos: Ponteiro para o amigo.
 * @pre Amigo inicializado corretamente.
 * @post Amigo inalterado.
 * @return Ponteiro para o usuário inserido.
*/
void *retornaUsuario(Amigos *amigos);

/**
 * @brief Libera o ponteiro de um Amigo, sem liberar seu conteúdo.
 * @param *amigos: Ponteiro para o Amigo.
 * @pre *amigos aponta corretamente.
 * @post Ponteiro para o amigo liberado sem alterar o usuário contido.
*/
void destroyAmigos(Amigos *amigos);

#endif