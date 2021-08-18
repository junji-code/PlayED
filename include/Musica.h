#ifndef MUSICA_H
#define MUSICA_H

#include "../include/Lista.h"

/**
 * @brief TAD de música.
*/

/**
 * @brief Cria uma lista de músicas com base em um arquivo.
 * @param *NomeArq: String do nome do arquivo.
 * @pre Arquivo de músicas escrito no formato esperado e *NomeArq com o nome correto e diferente de NULL.
 * @post Arquivo inalterado e lista de músicas corretamente carregada.
 * @return Ponteiro para a lista de músicas.
*/
tList *LeArquivoMusicas(char *NomeArq);

/**
 * @brief Inicializa uma lista de músicas.
 * @post Lista de músicas inicializada corretamente.
 * @return Ponteiro para a lista de músicas.
*/
tList *InitiMusica();

/**
 * @brief Consulta a string do nome da banda de uma música.
 * @param *musica: Ponteiro para a música.
 * @pre *música definido corretamente e diferente de NULL.
 * @post Música inalterada
 * @return String do nome da banda da música.
*/
char *retornaBanda(void *musica);

/**
 * @brief Compara se duas músicas são iguais(mesmo nome e banda).
 * @param *x: Ponteiro para a primeira música; *y: Ponteiro para a segunda música.
 * @pre *x e *y apontam corretamente e diferentes de NULL.
 * @post Músicas inalteradas.
 * @return 1 se forem iguais, 0 senão.
*/
int cmpMusica(void *x, void *y);

/**
 * @brief Imprime a banda e o nome de uma música.
 * @param *x: Ponteiro para a música a ser impressa.
 * @pre *x aponta para uma música e diferente de NULL.
 * @post Música inalterada.
*/
void ImprimeMusica(void *x);

/**
 * @brief Imprime a banda e o nome de uma música em um arquivo.
 * @param *x: Ponteiro para a música; *y: String do nome do arquivo.
 * @pre *x aponta para uma música, *y para uma string e são diferentes de NULL.
 * @post Música inalterada e música escrita no arquivo.
*/
void ImprimeMusicaArq(void *x, void *y);

/**
 * @brief Verifica se uma música pertence a uma lista de músicas.
 * @param *musica: Ponteiro para a música; *list: Ponteiro para a lista de músicas.
 * @pre *musica aponta para uma música, *list aponta para uma lista de músicas e ambas diferentes de NULL.
 * @post Música de lista inalteradas.
 * @return 1 se a música pertencer, 0 senão.
*/
int cmpListMusica(void *musica, void *list);

/**
 * @brief Libera os componentes internos de uma música, sem liberar seu ponteiro.
 * @param *x: Ponteiro para a música.
 * @pre *x aponta para uma música e é diferente de NULL.
 * @post Componentes internos da música liberados.
*/
void destroyMusica(void *x);

#endif //MUSICA_H