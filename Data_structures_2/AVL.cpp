#include "AVL.h"
#include "structs.h"
#include <iostream>
using namespace std;

//Calcule altura de um nó
int height_node(struct _Node_* node){
    if(node == NULL)
        return -1;
    else
        return node->height;
}
//Calcule o fator de balanceamento de um nó
int fatorBalanceamento_node(struct _Node_* node){
    int valor = (height_node(node->right))-(height_node(node->left));
    return valor;
}
//Calcula o maior valor
int maior(int x, int y){
    if(x > y)
        return x;
    else
        return y;
}
//Rotação a esquerda
AVLnode* RotationLL(AVLnode* root){
    AVLnode*node;
    node = root->left;
    root->left = node->right;
    root->height = maior(height_node(root->left),height_node(root->right)) + 1;
    node->height = maior(height_node(node->left),height_node(root)) + 1;
    root = node;
    return root;
}
//Rotação a direita
AVLnode* RotationRR(AVLnode* root){
    AVLnode* node;
    node = root->right;
    root->right = node->left;
    root->height = maior(height_node(root->left),height_node(root->right)) + 1;
    node->height = maior(height_node(node->right),height_node(root)) + 1;
    root = node;
    return root;
}
//Rotação dupla a esquerda
AVLnode* RotationLR(AVLnode* root){
    root->left = RotationRR(root->left);
    root = RotationLL(root);
    return root;
}
//Rotação dupla a direita
AVLnode* RotationRL(AVLnode* root){
    root->right = RotationLL(root->right);
    root = RotationRR(root);
    return root;
}
//Insert AVLtree
AVLnode* insert_AVLnode(AVLnode* root,Data* data){
    //árvore vazia ou nó folha
    if(root == NULL){
        AVLnode* novo;
        novo = new AVLnode[1];
        if(novo == NULL)
            return NULL;
        novo->data = data;
        novo->height = 0;
        novo->left = NULL;
        novo->right = NULL;
        return novo;
    }

    AVLnode* current = root;

    /*Balançeamento*/
    if(data->key < current->data->key){
        current->left = insert_AVLnode(current->left, data);
        if(current->left != NULL){
            if(fatorBalanceamento_node(current) <= -2){
                if(data->key < current->left->data->key)
                    root = RotationLL(root);
                else
                    root = RotationLR(root);
            }
        }
        return root;
    }else{
        if(data->key > current->data->key){
            current->right = insert_AVLnode(current->right, data);
            if(current->right != NULL){
                if(fatorBalanceamento_node(current) >= 2){
                    if(data->key > current->right->data->key)
                        root = RotationRR(root);
                    else
                        root = RotationRL(root);
                }
            }
        }
        return root;
    }
    return NULL;
}
//Query
void Query(AVLnode* root,Data** aux,int str,int* passos){

    if(root != NULL){
        if(root->data->key == str){
            *aux = root->data;
        }else if(str > root->data->key){
            Query(root->right, &*aux, str, &*passos);
        }else{
            Query(root->left, &*aux, str, &*passos);
        }
    }
    *passos = *passos + 1;
}
AVLnode* findMin(AVLnode* t) {//achar menor
        if(t == NULL)
            return NULL;
        else if(t->left == NULL)
            return t;
        else
            return findMin(t->left);
    }


AVLnode* AVLremove(int x, AVLnode* t) {
        AVLnode* temp;

        // Elemento nao encontrado
        if(t == NULL)
            return NULL;

        // procurar elemento
        else if(x < t->data->key)
            t->left = AVLremove(x, t->left);
        else if(x > t->data->key)
            t->right = AVLremove(x, t->right);

        // Elemento encontrado
        // Com 2 filhos
        else if(t->left && t->right)
        {
            temp = findMin(t->right);
            t->data = temp->data;
            t->right = AVLremove(t->data->key, t->right);
        }
        // Com 1 ou nenhum filho
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

       /* t->height = max(height(t->left), height(t->right))+1;

        // If node is unbalanced
        // If left node is deleted, right case
        if(height(t->left) - height(t->right) == 2)
        {
            // right right case
            if(height(t->left->left) - height(t->left->right) == 1)
                return singleLeftRotate(t);
            // right left case
            else
                return doubleLeftRotate(t);
        }
        // If right node is deleted, left case
        else if(height(t->right) - height(t->left) == 2)
        {
            // left left case
            if(height(t->right->right) - height(t->right->left) == 1)
                return singleRightRotate(t);
            // left right case
            else
                return doubleRightRotate(t);
        }*/
        return t;
    }



void AVLprint(AVLnode *no) { //printa AVL e verifica se as insercoes foram corretamente
    if(no != NULL) {
        cout << no->data->key <<" " << no->data->dado1 << " " << no->data->palavra << endl;
        AVLprint(no->left);
        AVLprint(no->right);
    }
}


//Destruir
void Destroy(AVLnode *t){
    if(t != NULL){
        Destroy(t->left);
        Destroy(t->right);
        delete[]t->data;
        delete[]t;
    }
}
