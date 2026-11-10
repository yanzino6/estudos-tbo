#ifndef BST_H_
#define BST_H_

typedef struct bst bst;

bst *bstInit();

void bstDestroy(bst *b);

int bstHeight(bst *b);

bst *bstInsertKey(bst *b, int key);

#endif