#ifndef MUSICA_H
#define MUSICA_H

typedef struct sMusica musicaSent;

void ImprimeMusicas(musicaSent* lista);

musicaSent* InitMusica();

void AddMusica(musicaSent* lista, char* linha);

char* RemoveMusica(musicaSent* lista, char* musica);

void destroyMusica(musicaSent* lista);

#endif//MUSICA_H

/*
FUNÇÕES SOMENTE DO .c

tMusica* SeparaMusica(char* linha);

int cmpMusica(tMusica* music1, tMusica* music2);

*/