#include "list.h"
#include "structs.h"
#include <iostream>
#include <string.h>

using namespace std;

/* main list
#include "lista.h"
#include<iostream>
#include <stdio.h>

using namespace std;

int main() {
    lista *minhaLista=NULL;
    char nome[50];
    char email[50];
    int flag=0, tam;
    char palavra[20];
    //lista *nova;


    while (flag<5) {  //insere 5 contatos na lista
        gets(nome);
        gets(email);
        insFim(&minhaLista, nome, email);
        imprimirLista(minhaLista);
        flag++;
    }

    tam = tamanho(minhaLista);
    cout << "Nome do contato a ser retirado: " << endl;
    gets(palavra);
    remover(&minhaLista, palavra);
    imprimirLista(minhaLista); //ja mostra a lista completa sem o contato retirado

return 0;
}
*/

lista *criar (Data *data){
    lista *novo;

    novo = new lista[1];
    novo->data = data;
    novo->prox = NULL;

    return novo;
}


void   insFim(lista **cab, Data *data) {

    lista *novo = new lista[1];
    if(novo!=NULL) {
        novo->data=data;
        novo->prox=NULL;
    }
    lista *tmp = *cab;


    if (*cab  == NULL) {
        *cab = novo;
    }
    else {


        while( tmp->prox != NULL) {
            tmp = tmp->prox;
        }


        tmp->prox = novo;
    }
}

void listaQuery(lista* root,Data** aux,int str, int* passos) {
    //int value = valorString(str);
    if(root != NULL){
        if(root->data->key == str){
            *aux = root->data;
        }else {
            listaQuery(root->prox, &*aux, str, &*passos);
    }
    *passos = *passos + 1;
}
}

int listaDestroy(lista* root) {

    if(root!=NULL) {
        lista* aux = root;
        lista *next = aux->prox;
        while(next!=NULL) {
            //aux->data->linhas.clear();
            //aux->data->ocorrencias.clear();
            delete [] aux->data;
            delete [] aux;
            next = next->prox;
        }
       // next->data->linhas.clear();
            //next->data->ocorrencias.clear();
            delete [] next->data;
            delete [] next;
        return 1;
    }
    return 0;
}
/*


void imprimirLista(lista *cab) {
    lista *tmp = cab;
    while (tmp != NULL) {
        cout <<"elm: " << tmp->pessoa.nome << " " << tmp->pessoa.email << "\n";
        tmp = tmp->prox;
    }

}

int tamanho(lista *cab) {
    int aux = 0;
    lista *tmp = cab;

    while (tmp!=NULL) {
        aux++;
        tmp = tmp->prox;
    }
    return aux;

}


void remover(lista **cab, char *palavra) {

    lista *tmp = *cab;
    lista *ant;

    while ((tmp!=NULL) && (strcmp(tmp->pessoa.nome, palavra)==0)) {
        *cab = tmp->prox;
        delete [] tmp->pessoa.
        nome;
        delete [] tmp->pessoa.email;
        tmp = *cab;
    }

    while (tmp!=NULL) {
        while ((tmp!=NULL) && (strcmp(tmp->pessoa.nome, palavra)!=0)) {
            ant = tmp;
            tmp = tmp->prox;
        }
        if (tmp==NULL) return;
        ant->prox = tmp->prox;
        delete [] tmp->pessoa.nome;
        delete [] tmp->pessoa.email;

        tmp = ant->prox;
    }
}*/

