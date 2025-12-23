#include "bst.h"
#include <iostream>
using namespace std;

Node* root = NULL;

// buat BST
void createTree() {
    root = NULL;
}

bool isEmpty() {
    return root == NULL;
}

// buat node baru
Node* newNode(string nama, float berat, string tier) {
    Node* temp = new Node;
    temp->namaMember = nama;
    temp->beratBadan = berat;
    temp->tierMember = tier;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// insert node BST
Node* insertNode(Node* curr, Node* nodeBaru) {
    if (curr == NULL)
        return nodeBaru;

    if (nodeBaru->beratBadan < curr->beratBadan)
        curr->left = insertNode(curr->left, nodeBaru);
    else
        curr->right = insertNode(curr->right, nodeBaru);

    return curr;
}

// traversal inorder 
void inOrder(Node* curr) {
    if (curr != NULL) {
        inOrder(curr->left);
        cout << curr->beratBadan << " - ";
        inOrder(curr->right);
    }
}

// node paling kiri
Node* mostLeft() {
    if (root == NULL) return NULL;

    Node* curr = root;
    while (curr->left != NULL)
        curr = curr->left;

    return curr;
}

// node paling kanan
Node* mostRight() {
    if (root == NULL) return NULL;

    Node* curr = root;
    while (curr->right != NULL)
        curr = curr->right;

    return curr;
}

// search biasa
Node* searchByBeratBadan(Node* curr, float berat) {
    if (curr == NULL || curr->beratBadan == berat)
        return curr;

    if (berat < curr->beratBadan)
        return searchByBeratBadan(curr->left, berat);
    else
        return searchByBeratBadan(curr->right, berat);
}

// search + parent
Node* searchWithParent(Node* curr, float berat, Node*& parent) {
    parent = NULL;

    while (curr != NULL) {
        if (curr->beratBadan == berat)
            return curr;

        parent = curr;
        if (berat < curr->beratBadan)
            curr = curr->left;
        else
            curr = curr->right;
    }
    return NULL;
}
