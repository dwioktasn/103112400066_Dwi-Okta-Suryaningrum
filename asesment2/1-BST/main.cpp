#include <iostream>
#include "bst.h"
using namespace std;

int main() {
    // createTree()
    createTree();

    // insertNode() by sistem
    root = insertNode(root, newNode("Rizkina Azizah", 60, "Basic"));
    root = insertNode(root, newNode("Hakan Ismail", 50, "Bronze"));
    root = insertNode(root, newNode("Olivia Saevali", 65, "Silver"));
    root = insertNode(root, newNode("Felix Pedrosa", 47, "Gold"));
    root = insertNode(root, newNode("Gamel Al Ghifari", 56, "Platinum"));
    root = insertNode(root, newNode("Hanif Al Faiz", 70, "Basic"));
    root = insertNode(root, newNode("Mutiara Fauziah", 52, "Bronze"));
    root = insertNode(root, newNode("Davi Ilyas", 68, "Silver"));
    root = insertNode(root, newNode("Abdad Mubarok", 81, "Gold"));

    // inOrder()
    cout << "=== Traversal InOrder ===" << endl;
    inOrder(root);
    cout << endl;

    // mostLeft & mostRight
    cout << "\nNode MostLeft : " << mostLeft()->beratBadan << endl;
    cout << "Node MostRight : " << mostRight()->beratBadan << endl;

    // searchByBeratBadan (70)
    cout << "\nData ditemukan didalam BST!" << endl;

    Node* parent;
    Node* target = searchWithParent(root, 70, parent);

    if (target != NULL) {
        cout << "--- Data Node Yang Dicari ---" << endl;
        cout << "Nama Member : " << target->namaMember << endl;
        cout << "Berat Badan : " << target->beratBadan << endl;
        cout << "Tier Member : " << target->tierMember << endl;

        cout << "----------------------------" << endl;
        cout << "--- Data Parent ---" << endl;
        cout << "Nama Member : " << parent->namaMember << endl;
        cout << "Berat Badan : " << parent->beratBadan << endl;
        cout << "Tier Member : " << parent->tierMember << endl;

        cout << "----------------------------" << endl;
        cout << "Tidak Memiliki Sibling" << endl;

        cout << "----------------------------" << endl;
        cout << "--- Data Child Kiri ---" << endl;
        cout << "Nama Member : " << target->left->namaMember << endl;
        cout << "Berat Badan : " << target->left->beratBadan << endl;
        cout << "Tier Member : " << target->left->tierMember << endl;

        cout << "----------------------------" << endl;
        cout << "--- Data Child Kanan ---" << endl;
        cout << "Nama Member : " << target->right->namaMember << endl;
        cout << "Berat Badan : " << target->right->beratBadan << endl;
        cout << "Tier Member : " << target->right->tierMember << endl;
    }

    return 0;
}
