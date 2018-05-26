#ifndef LISTA_H

#define LISTA_H
#include "structs.h"

typedef struct _contato_ {
    char *nome;
    char *email;

} contato;

typedef struct _lista_ {
    struct _data_ *data;
    struct _lista_ *prox;

}lista;


//lista *insInicio(lista *cab, char * dado);


//void   insInicio(lista **cab, char * dado);

lista *criar (Data *data);

//lista *insFim(lista *cab, char *dado);
void   insFim(lista **cab, Data *data);
void listaQuery(lista* root,Data** aux,int str, int* passos);
int listaDestroy(lista* root);

void imprimirLista(lista *cab);

int tamanho(lista *cab);

void remover(lista **cab, char *palavra);

#endif
