#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list tList;

typedef void (*fptrGeneric)(void *x);

typedef void (*fptrGeneric2)(void *x, void *y);

//deve retornar o proprio X se for igual, senão NULL
typedef int (*fptrCompare)(void *x, void *find);

tList *NewList(int DataSize, fptrGeneric destroy);

void DestroyList(tList *list);

void addBase(tList *list, void *data);

void addEnd(tList *list, void *data);

void RemoveBase(tList *list);

void *removeReturnBase(tList *list);

void RemoveEnd(tList *list);

void genericFunctionList(tList *list, fptrGeneric genericFunction);

void genericFunction2List(tList *list, void *, fptrGeneric2 genericFunction);

int Counter(tList *list, void *find, fptrCompare function);

//retorna o ponteiro de info sem remover da lista
void *SearchList(tList *list, void *find, fptrCompare function);

//Retorna o pontriro de info e remove a celula da lista se for achado
void *SearchRemoveList(tList *list, void *find, fptrCompare function);

void Check(void *x);

#endif //LISTA_H