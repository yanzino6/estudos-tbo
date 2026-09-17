#ifndef BST_H
#define BST_H

typedef struct bst bst;

bst *criaBST();

bst *insereNaBST(bst *b, int v);

void destroiBst(bst *b);

void imprimeBst(bst *b, int space);

int alturaBst(bst *b);

void rec_preorder(bst *t, void (*visit)(bst*));

void rec_inorder(bst *t, void (*visit)(bst*));

void rec_postorder(bst *t, void (*visit)(bst*));

void nonrec_preorder(bst *t, void (*visit)(bst*));

void nonrec_inorder(bst *t, void (*visit)(bst*));

void nonrec_postorder(bst *t, void (*visit)(bst*));

void printValue(bst * b);

#endif