#include"Binary.h"
#include"stdlib.h"
#include"stdio.h"
#include "structs.h"

using namespace std;


/*Bnode *tCreate() {
    Bnode *t;
    t = new Bnode[1];
    if (t==NULL) return NULL;
    *t = NULL;
    //t->left = NULL;
    //t->right = NULL;
    return t;
}*/

void B_Insert(Bnode **r, Data *data) {

    if (r == NULL) return;
    if (*r == NULL) {
        Bnode *novo;
        novo = new Bnode[1];
        novo->data = data;
        novo->left = NULL;
        novo->right = NULL;
        *r = novo;
        return;
    } else {
    Bnode* current = *r;
    if (data->key < current->data->key) {
       B_Insert(&(current->left), data);
       return;
    }
    if (data->key > current->data->key){
       B_Insert(&(current->right), data);
       return;
    }
    }

}

void BinaryQuery(Bnode* root,Data** aux,int str,int* passos) {
//int value = valorString(str);
    if(root != NULL){
        if(root->data->key == str){
            *aux = root->data;
        }else if(str > root->data->key){
            BinaryQuery(root->right, &*aux, str, &*passos);
        }else{
            BinaryQuery(root->left, &*aux, str, &*passos);
        }
    }
    *passos = *passos + 1;

}

void tDestroyNode(Bnode *no) {
    if(no == NULL) return;
    tDestroyNode(no->left);
    tDestroyNode(no->right);
    // no->data->linhas.clear();
    //  no->data->ocorrencias.clear();
      delete [] no->data;
     delete [] no;
    free(no);
    no = NULL;

}


void tDestroy(Bnode *raiz) {
    if (raiz == NULL) return;
    tDestroyNode(raiz); //libera cada no
     //raiz->data->linhas.clear();
        //raiz->data->ocorrencias.clear();
     delete [] raiz->data;
     delete [] raiz;
    //free(raiz); // libera a raiz
    raiz = NULL;

}



