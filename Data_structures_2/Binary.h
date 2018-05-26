#ifndef _BINARY_H_
#define _BINARY_H_
#include "structs.h"

typedef struct _node_ {
    struct _data_ *data;
    struct _node_ *left;
    struct _node_ *right;

} Bnode;

//typedef Bnode *tree;

Bnode *tCreate();
void tDestroyNode(Bnode *no);
void tDestroy(Bnode *root);
void B_Insert(Bnode **r, Data *data);
void BinaryQuery(Bnode* root,Data** aux,int str,int* passos);

#endif // _BINARY_H_
