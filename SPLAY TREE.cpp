#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node *left, *right;
};

struct Node* newNode(int key) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

struct Node* rightRotate(struct Node* root) {
    struct Node* newRoot = root->left;
    root->left = newRoot->right;
    newRoot->right = root;
    return newRoot;
}

struct Node* leftRotate(struct Node* root) {
    struct Node* newRoot = root->right;
    root->right = newRoot->left;
    newRoot->left = root;
    return newRoot;
}

struct Node* splay(struct Node* root, int key) {
    if (root == NULL || root->key == key) return root;

    if (root->key > key) {
        if (root->left == NULL) return root;

        if (root->left->key > key) {
            root->left = splay(root->left, key);
            root = rightRotate(root);
        } else if (root->left->key < key) {
            root->left->right = splay(root->left->right, key);
            if (root->left->right != NULL)
                root->left = leftRotate(root->left);
        }
        return (root->left == NULL) ? root : rightRotate(root);
    } else {
        if (root->right == NULL) return root;

        if (root->right->key < key) {
            root->right = splay(root->right, key);
            root = leftRotate(root);
        } else if (root->right->key > key) {
            root->right->left = splay(root->right->left, key);
            if (root->right->left != NULL)
                root->right = rightRotate(root->right);
        }
        return (root->right == NULL) ? root : leftRotate(root);
    }
}

struct Node* insert(struct Node* root, int key) {
    if (root == NULL) return newNode(key);
    root = splay(root, key);
    if (root->key == key) return root;

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;

    if (root->key > key) {
        newNode->right = root;
        newNode->left = root->left;
        root->left = NULL;
    } else {
        newNode->left = root;
        newNode->right = root->right;
        root->right = NULL;
    }
    return newNode;
}

void preOrder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    root = insert(root, 30);
    root = insert(root, 15);
    root = insert(root, 57);
    root = insert(root, 23);
    root = insert(root, 10);

    printf("Preorder traversal of the splay tree is: ");
    preOrder(root);
    return 0;
}
