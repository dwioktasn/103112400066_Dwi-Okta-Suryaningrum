#include "bstree.h"

address alokasi(infotype x) {
    address temp = new Node;
    temp->info = x;
    temp->left = nullptr;
    temp->right = nullptr;
    return temp;
}

void insertNode(address &root, infotype x) {
    if (root == nullptr) {
        root = alokasi(x);
        return; // stop di sini kalau baru dibuat
    }

    if (x < root->info) {
        insertNode(root->left, x);
    } else if (x > root->info) {
        insertNode(root->right, x);
    }
    // kalau x == root->info → diabaikan (tidak simpan duplikat)
}

address findNode(address root, infotype x) {
    if (root == nullptr || root->info == x) {
        return root;
    }

    if (x < root->info) {
        return findNode(root->left, x);
    } else {
        return findNode(root->right, x);
    }
}

void printInorder(address root) {
    if (root != nullptr) {
        printInorder(root->left);
        cout << root->info << " - ";
        printInorder(root->right);
    }
}

int hitungKedalaman(address root, int start) {
    if (root == nullptr) {
        return start;
    } else {
        int leftDepth = hitungKedalaman(root->left, start + 1);
        int rightDepth = hitungKedalaman(root->right, start + 1);
        return (leftDepth > rightDepth) ? leftDepth : rightDepth;
    }
}

// versi tanpa parameter start (biar simpel dipanggil di main)
int hitungTotalInfo(address root) {
    if (root == nullptr) {
        return 0;
    } else {
        return root->info
             + hitungTotalInfo(root->left)
             + hitungTotalInfo(root->right);
    }
}

int hitungJumlahNode(address root) {
    if (root == nullptr) {
        return 0;
    } else {
        return 1
             + hitungJumlahNode(root->left)
             + hitungJumlahNode(root->right);
    }
}