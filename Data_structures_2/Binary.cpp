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

void B_Insert(Bnode** root, Data* data){
    Bnode* y = NULL;
    Bnode* x = *root;
    while(x != NULL){
        y = x;
        if(data->key < x->data->key)
            x = x->left;
        else
            x = x->right;
    }
    Bnode* newnode = new Bnode[1];
    if(newnode != NULL){
        newnode->data = data;
        newnode->left = NULL;
        newnode->right = NULL;
    }
    if(y == NULL){
        *root = newnode;
    }else{
        if(data->key < y->data->key)
            y->left = newnode;
        else
            y->right = newnode;
    }
}

/*void B_Insert(Bnode **r, Data *data) {

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

}*/

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

Bnode* findMin(Bnode* t) { //achar o antecessor
        if(t == NULL)
            return NULL;
        else if(t->left == NULL)
            return t;
        else
            return findMin(t->left);
    }


Bnode* Bremove(int x, Bnode* t) {
        Bnode* temp;

        // Elemento nao encontrado
        if(t == NULL)
            return NULL;

        // Procurando elemento
        else if(x < t->data->key)
            t->left = Bremove(x, t->left);
        else if(x > t->data->key)
            t->right = Bremove(x, t->right);

        // Elemento encontrado
        // Com dois filhos
        else if(t->left && t->right)
        {
            temp = findMin(t->right);
            t->data = temp->data;
            t->right = Bremove(t->data->key, t->right);
        }
        // 1 ou nenhum filho
        else
        {
            temp = t;
            if(t->left == NULL)
                t = t->right;
            else if(t->right == NULL)
                t = t->left;
            delete temp;
        }
        if(t == NULL)
            return t;

        return t;
    }

void tDestroyNode(Bnode *no) {
    if(no == NULL) return;
    tDestroyNode(no->left);
    tDestroyNode(no->right);
      delete [] no->data;
     delete [] no;
    no = NULL;

}


void tDestroy(Bnode *raiz) {
    if (raiz == NULL) return;
    tDestroyNode(raiz); //libera cada no
     delete [] raiz->data;
     delete [] raiz;
    //free(raiz); // libera a raiz
}



