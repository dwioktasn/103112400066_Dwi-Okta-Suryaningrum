#ifndef BST_H
#define BST_H

#include <string>
using namespace std;

// Struktur node BST
struct Node {
    string namaMember;
    float beratBadan;
    string tierMember;
    Node* left;
    Node* right;
};

// root BST
extern Node* root;

// prototype function
bool isEmpty();
void createTree();

Node* newNode(string nama, float berat, string tier);
Node* insertNode(Node* curr, Node* nodeBaru);

Node* searchByBeratBadan(Node* curr, float berat);
Node* searchWithParent(Node* curr, float berat, Node*& parent);
Node* mostLeft();
Node* mostRight();

void inOrder(Node* curr);

#endif
