#ifndef USUARIO_H
#define USUARIO_H
#include "../include/Lista.h"

/**
 * @brief TAD de usuário.
*/
typedef struct usuario Usuario;

/**
 * @brief Libera as listas de amigos e playlists, sem liberar seu conteúdo, e o nome.
 * @param *usuario: Ponteiro para o usuário.
 * @pre Ponteiro apontando corretamente para o usuário.
 * @post Usuário liberado, sem liberar o ponteiro *usuario.
*/
void destroyUsuario(void *usuario);

/**
 * @brief Compara o nome de um usuário com uma string.
 * @param *usu: Ponteiro para o usuário; *nom: Ponteiro para a string
 * @pre *usu e *nom apontando corretamente.
 * @post Nada acontece com o usuário e com a string.
 * @return 1 se são iguais e 0 senão.
*/
int comparaNome(void *usu, void *nom);

/**
 * @brief Lê o arquivo de usuários para inicializá-los.
 * @param *arq: Nome do arquivo.
 * @pre Arquivo com nome *arq existe e está preenchido no formato correto.
 * @post Lista de usuários corretamente inicializada, sem alterar o arquivo.
 * @return Ponteiro para a lista de usuários.
*/
tList *inicializaUsuarios(char *arq);

/**
 * @brief Imprime o conteúdo de um usuário.
 * @param *amigos: Ponteiro para o usuário.
 * @pre *amigos aponta corretamente para o usuário e é diferente de NULL.
 * @post Usuário não é alterado e suas informações são impressas corretamente.
*/
void imprimeAmigos(void *amigos);

/**
 * @brief Inicializa as playlists dos usuários de acordo com um arquivo de playlists.
 * @param *usuarios: Ponteiro para a lista de usuários; *nomeArq: String do nome do arquivo.
 * @pre *usuarios e *nomeArq definidos corretamente.
 * @post Playlists inseridas e arquivo inalterado.
*/
static void inserePlaylists(tList *usuarios, char *nomeArq);

/**
 * @brief Refatora as playlists de um determinado usuário.
 * @param *pusuario: Ponteiro para o usuário.
 * @pre *pusuario aponta corretamente.
 * @post Playlists do usuário refatoradas de acordo com o nome dos artistas.
*/
void refatoraPlaylists(void *pusuario);

/**
 * @brief Escreve as informações do usuário no arquivo "played-refatorada.txt" e imprime os arquivos das playlists em uma pasta com o nome do usuário.
 * @param *pusuario: Ponteiro para o usuário.
 * @pre *pusuario aponta para um usuário.
 * @post Arquivos e pastas criados e escritos corretamente, sem alterar o usuário.
*/
void ImprimeArqRefatorada(void *pusuario);

/**
 * @brief Escreve o arquivo "similaridades.txt" com a quantidade de similaridades(mesmas músicas) entre os amigos.
 * @param *usuarios: Ponteiro para a lista de usuários; *arqAmizades: String com o nome do arquivo de amizades.
 * @pre *usuarios e *arqAmizades definidos corretamente; Arquivo com o nome apontado por *arqAmizades preenchido no formato correto.
 * @post Lista de usuários inalterada; Arquivo de similaridades na pasta correta e escrito como o esperado.
*/
void Similaridade(tList *usuarios, char *arqAmizades);

#endif