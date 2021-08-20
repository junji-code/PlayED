#ifndef FILES_H
#define FILES_H

#include <stdio.h>

/**
 * @brief Abre um arquivo do modo passado e com o nome passado no diretorio de entrada definido no .c.
 * @param *NomeArq Nome do arquivo a ser aberto.
 * @param *mode Modo de abertura
 * @pre A pasta de entrada deve existir, dever do usuario.
 * @post Um arquivo aberto no diretorio de entrada se existir, senão ele fecha o programa com exit.
 * @return Ponteiro do arquivo aberto.
*/
FILE* OpenFileIn(char *NomeArq, char *mode);

/**
 * @brief Abre um arquivo do modo passado e com o nome passado no diretorio de saida definido no .c.
 * @param *NomeArq Nome do arquivo a ser aberto.
 * @param *mode Modo de abertura
 * @pre Modo deve estar certo e a pasta de saida deve existir, dever do usuario.
 * @post Um arquivo aberto no diretorio de saida se existir, senão ele fecha o programa com exit.
 * @return Ponteiro do arquivo aberto.
*/
FILE* OpenFileOut(char *NomeArq, char *mode);

/**
 * @brief Cria uma pasta no diretorio de saida com o nome passado.
 * @param *nome String com o nomeda pasta a ser criada.
 * @pre A pasta de saida de existir, dever do usuario.
 * @post Novo diretorio criado.
*/
void CreateOutDir(char *nome);

#endif//FILES_H