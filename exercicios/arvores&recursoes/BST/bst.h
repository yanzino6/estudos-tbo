#ifndef BST_H
#define BST_H

typedef struct bst bst;

bst *criaBST();

bst *insereNaBST(bst *b, int v);

void destroiBst(bst *b);

void imprimeBst(bst *b, int space);

#endif