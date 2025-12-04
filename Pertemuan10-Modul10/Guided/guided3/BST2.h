#ifndef BST1_H
#define BST1_H

#include <iostream>
using namespace std;

typedef int infotype; //alias infotype untuk data integer
typedef struct Node *address; //alias address sebagai pointer ke struct Node(Node*)

struct Node{
    infotype info; //info data yang disimpan (integer)
    address left; //pointer ke anak kiri (left)
    address right; //pointer ke anak kanan (right)
};

// ISEMPTY AND CREATE
bool isEmpty(address root); //function untuk mengecek apakah bst kosong atau tidak
void createTree(address &root); //function untuk membuat bstnya (root di set sebagai null)

// ALOKASI DAN INSERT
address newNode(infotype x); // function untuk memasukkan fata(infotype) ke dalam node bst
address insertNode(address root, infotype x); //function untuk memasukkan node kedalam bst

// TRAVERSAL
void preOrder(address root); //function untuk menampilkan data bst secara preOrder (TENGAH, KIRI, KANAN ATAU ROOT-CHILD KIRI-CHILD KANAN)
void inOrder(address root); //function untuk menampilkan data bst secara inOrder (KIRI, TENGAH, KANAN ATAU CHILD KIRI-ROOT-CHILD KANAN)
void postOrder(address root); //function untuk menampilkan data bst secara postOrder (KIRI, KANAN, TENGAH ATAU CHILD KIRI-CHILD KANAN-ROOT)


// UTILITIES
int countNodes(address root); //function untuk menghitung size atau ukuran atau jumlah node yangg adam didalam tree
int treeDepth(address root); //function untuk menghitung height atau kedalaman atau level tree

// FUNCTION 2 PROSEDUR BARU
// SEARCHING
void searchByData(address root, infotype x); //function untuk melakukan searching data tertentu 

//mostleft dan mostright
address mostLeft(address root); //function untuk menampilkan mostleft atau node paling kiri (node dengan nilai paling kecil di bst)
address mostRight(address root); //function untuk menampilkan mostright atau node paling kanan (node dengan nilai paling besar di bst)

//delete
bool deleteNode(address &root, infotype x); //function untuk menghapus node dengan info x pada bst, mengembalikan true jika berhasil dihapus, false jika tidak ditemukan
void deleteTree(address &root); //function untuk menghapus semua node pada bst
#endif