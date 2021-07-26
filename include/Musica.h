#ifndef MUSICA_H
#define MUSICA_H

typedef struct sMusica musicaSent;

musicaSent* InitMusica();

void AddMusica(musicaSent* lista, char* linha);

char* RemoveMusica(musicaSent* lista, char* musica);

void destroyMusica(musicaSent* lista);

void ImprimeMusicas(musicaSent* lista);

#endif//MUSICA_H