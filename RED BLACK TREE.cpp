#include <stdio.h>
#include <stdlib.h>

typedef enum { RED, BLACK } NodeColor;

typedef struct RBTreeNode {
    int data;
    NodeColor color;
    struct RBTreeNode *left, *right, *parent;
} RBTreeNode;

typedef struct RBTree {
    RBTreeNode *root;
    RBTreeNode *nil; 
} RBTree;


RBTreeNode* createNode(RBTree *tree, int data);
RBTree* createRBTree();
void leftRotate(RBTree *tree, RBTreeNode *x);
void rightRotate(RBTree *tree, RBTreeNode *y);
void insertFixup(RBTree *tree, RBTreeNode *z);
void insert(RBTree *tree, int data);
void inorderTraversal(RBTreeNode *node, RBTreeNode *nil);
void printTree(RBTree *tree);

RBTreeNode* createNode(RBTree *tree, int data) {
    RBTreeNode newNode = (RBTreeNode)malloc(sizeof(RBTreeNode) );
    newNode->data = data;
    newNode->color = RED; 
    newNode->left = tree->nil;
    newNode->right = tree->nil;
    newNode->parent = tree->nil;
    return newNode;
}


RBTree* createRBTree() {
    RBTree tree = (RBTree)malloc(sizeof(RBTree));
    tree->nil = (RBTreeNode*)malloc(sizeof(RBTreeNode));
    tree->nil->color = BLACK;
    tree->root = tree->nil;
    return tree;
}
void leftRotate(RBTree *tree, RBTreeNode *x) {
    RBTreeNode *y = x->right;
    x->right = y->left;
    if (y->left != tree->nil) {
        y->left->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == tree->nil) {
        tree->root = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
}


void rightRotate(RBTree *tree, RBTreeNode *y) {
    RBTreeNode *x = y->left;
    y->left = x->right;
    if (x->right != tree->nil) {
        x->right->parent = y;
    }
    x->parent = y->parent;
    if (y->parent == tree->nil) {
        tree->root = x;
    } else if (y == y->parent->right) {
        y->parent->right = x;
    } else {
        y->parent->left = x;
    }
    x->right = y;
    y->parent = x;
}


void insertFixup(RBTree *tree, RBTreeNode *z) {
    while (z->parent->color == RED) {
        if (z->parent == z->parent->parent->left) {
            RBTreeNode *y = z->parent->parent->right; 
            if (y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->right) {
                    z = z->parent;
                    leftRotate(tree, z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rightRotate(tree, z->parent->parent);
            }
        } else {
            RBTreeNode *y = z->parent->parent->left;
            if (y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->left) {
                    z = z->parent;
                    rightRotate(tree, z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                leftRotate(tree, z->parent->parent);
            }
        }
    }
    tree->root->color = BLACK;
}


void insert(RBTree *tree, int data) {
    RBTreeNode *z = createNode(tree, data);
    RBTreeNode *y = tree->nil;
    RBTreeNode *x = tree->root;

    while (x != tree->nil) {
        y = x;
        if (z->data < x->data) {
            x = x->left;
        } else {
            x = x->right;
        }
    }

    z->parent = y;
    if (y == tree->nil) {
        tree->root = z;
    } else if (z->data < y->data) {
        y->left = z;
    } else {
        y->right = z;
    }

    insertFixup(tree, z);
}


void inorderTraversal(RBTreeNode *node, RBTreeNode *nil) {
    if (node != nil) {
        inorderTraversal(node->left, nil);
        printf("%d (%s)\n", node->data, node->color == RED ? "Red" : "Black");
        inorderTraversal(node->right, nil);
    }
}


void printTree(RBTree *tree) {
    inorderTraversal(tree->root, tree->nil);
}


int main() {
    RBTree *tree = createRBTree();


    insert(tree, 10);
    insert(tree, 20);
    insert(tree, 30);
    insert(tree, 15);
    insert(tree, 25);
    insert(tree, 5);
    insert(tree, 1);

    
    printf("In-order Traversal of Red-Black Tree:\n");
    printTree(tree);

    return 0;
}
