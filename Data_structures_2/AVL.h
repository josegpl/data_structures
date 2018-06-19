#ifndef _AVL_H_
#define _AVL_H_
#include "structs.h"

typedef struct _Node_{
    struct _data_ *data;
    int height;
    struct _Node_ *left;
    struct _Node_ *right;
} AVLnode;

int height_node(struct _Node_* node);
int fatorBalanceamento_node(struct _Node_* node);
int maior(int x, int y);
AVLnode* RotationLL(AVLnode* root);
AVLnode* RotationRR(AVLnode* root);
AVLnode* RotationLR(AVLnode* root);
AVLnode* RotationRL(AVLnode* root);
AVLnode* findMin(AVLnode* t);
AVLnode* AVLremove(int x, AVLnode* t);
/*AVLnode* avlAntecessor(AVLnode* no);
AVLnode* avlRemove (AVLnode* atual, int key);*/
void AVLprint(AVLnode *no);

AVLnode* insert_AVLnode(AVLnode* root,Data* data);
void Query(AVLnode* root,Data** aux,int str, int* passos);
void Destroy(AVLnode *t);

#endif

