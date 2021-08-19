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
 * @post Se a musica não estiver naquela playlist
 * @return 
*/
void pushMusica(void *playlist, void *musica);

/**
 * @brief 
 * @param 
 * @pre 
 * @post 
 * @return 
*/
void DestroyPlaylist(void *playlist);

/**
 * @brief 
 * @param 
 * @pre 
 * @post 
 * @return 
*/
void *removePrimMusica(void *playlist);

/**
 * @brief 
 * @param 
 * @pre 
 * @post 
 * @return 
*/
int cmpNomePlaylist(void *play1, void *banda);

/**
 * @brief 
 * @param 
 * @pre 
 * @post 
 * @return 
*/
char *retornaNomePlaylist(void* play);
/**
 * @brief 
 * @param 
 * @pre 
 * @post 
 * @return 
*/
void imprimeNomePlaylistArq(void* play, void * file);

/**
 * @brief 
 * @param 
 * @pre 
 * @post 
 * @return 
*/
void ImprimePlayPasta(void* play, void* dir);

/**
 * @brief 
 * @param 
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