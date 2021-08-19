#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "../include/Lista.h"

/**
 * @brief Imprime playlist passada com todas a musicas.
 * @param *play Playlist a ser impressa.
 * @pre A playlist tem que ser valida, dever do usuario.
 * @post Playlist não alterada.
*/
void ImprimePlaylist(void *play);

/**
 * @brief Inicia uma lista de playlist.
 * @pre Deve ter memoria suficiente pra alocar, função verifica.
 * @post Uma lista nova alocada com as cunçoes e tamanho passado.
 * @return Uma nova lista de playlist alocada.
*/
tList *InitPlaylist();

/**
 * @brief Carrega uma nova playlist na list com o nome passado.
 * @param *lista Lista genetida de playlist.
 * @param *NomeArq Nome do arquivo onde estão as musicas.
 * @pre A lista deve ser de playlist e o nome do arquivo deve ser correto, dever do usuario.
 * @post Carrega uma nova playlist com as musicas do arquivo com o nome passado para a função.
*/
void CarregaPlaylist(tList *lista, char *NomeArq);

/**
 * @brief Inicia uma nova playlist com o nome passado e com a musica passada.
 * @param *lista Lista genetida de playlist.
 * @param *nome Nome da playlist a ser alocada.
 * @param *musica Uma musica a ser alocada na nova playlist.
 * @pre A lista ser de playlist, dever do usuario.
 * @post Adiciona uma nova playlist com amusica na lista passada.
*/
void addPlaylist(tList* lista, char *nome, void *musica);

/**
 * @brief Adiciona essa musica naquela playlist se não tiver uma musica igual.
 * @param *playlist Ponteiro de playlist.
 * @param *musica Ponteiro de musica.
 * @pre Não deve ter essa musica nessa playlist, verificada dentro da função.
 * @post Playlist com a musica não estiver naquela playlist, se estiver ela é liberada.
*/
void pushMusica(void *playlist, void *musica);

/**
 * @brief Destroy a playlist passada.
 * @param *playlist Playlist com as musicas.
 * @pre Playlist deve ser alocada, dever do usuario.
 * @post A playlist toda liberada.
*/
void DestroyPlaylist(void *playlist);

/**
 * @brief Remove a primeira musica da playlist.
 * @param *playlist Ponteiro de playlist.
 * @pre A lista de musica deve ser alocada, verificada dentro da função.
 * @post A playlist sem primeira musica.
 * @return O ponteiro da primeira musica da playlist. 
*/
void *removePrimMusica(void *playlist);

/**
 * @brief Compara uma string com o nome de uma playlist.
 * @param *play1 Ponteiro de playlist.
 * @param *banda String a ser compara com o nomde da playlist.
 * @pre Play1 deve ser ponteiro de playlist e banda deve ser string, deverr do usuario.
 * @return Retorna 1 se for igual, ou 0 se não for.
*/
int cmpNomePlaylist(void *play1, void *banda);

/**
 * @brief Imprime o nome da playlist no arquivo passado
 * @param *play Ponteiro de playlist.
 * @param *file Ponteiro de arquivo aberto.
 * @pre *play deve ser ponteiro de playlist e file de arquivo.
 * @post Nome da playlist impresso no arquivo.
*/
void imprimeNomePlaylistArq(void *play, void *file);

/**
 * @brief Imprime a as musicas da playlist no arquivo com o nome da playlist na pasta de saida.
 * @param *play Ponteiro de playlist.
 * @param *dir String com o diretorio.
 * @pre 
 * @post 
 * @return 
*/
void ImprimePlayPasta(void* play, void* dir);

/**
 * @brief Compara uma playlist com uma lista de playlist e retorna a quantodade de musicas iguais.
 * @param *play Ponteiro de playlist.
 * @param *list Lista de playlist.
 * @pre 
 * @post 
 * @return 
*/
int cmpPlayAmigos(void* play1, void* list);

/**
 * @brief 
 * @param 
 * @pre 
 * @post 
 * @return 
*/
int cmpPlaylist(void* play1, void* play2);

#endif //PLAYLIST_H