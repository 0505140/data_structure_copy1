#include <stdio.h>
#include <stdlib.h>

typedef char E;
typedef struct TreeNode{
    E element;
    struct TreeNode * left;
    struct TreeNode * right;
} * Node;

void preOrder(Node root){
    if(!root) return;
    printf("%c ", root->element);
    preOrder(root->left);
    preOrder(root->right);
}

void InOrder(Node root){
    if(!root) return;
    InOrder(root->left);
    printf("%c ", root->element);
    InOrder(root->right);
}

void PostOrder(Node root){
    if(!root) return;
    PostOrder(root->left);
    PostOrder(root->right);
    printf("%c ", root->element);
}

int main() {
    struct TreeNode root;
    Node a = malloc(sizeof (struct TreeNode));
    Node b = malloc(sizeof (struct TreeNode));
    Node c = malloc(sizeof (struct TreeNode));
    Node d = malloc(sizeof (struct TreeNode));
    Node e = malloc(sizeof (struct TreeNode));
    a->element = 'A';
    b->element = 'B';
    c->element = 'C';
    d->element = 'D';
    e->element = 'E';

    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    d->left = NULL;
    d->right = NULL;
    e->left = NULL;
    e->right = NULL;
    c->left = NULL;
    c->right = NULL;

    preOrder(a);
    putchar('\n');
    InOrder(a);
    putchar('\n');
    PostOrder(a);
    return 0;
}
