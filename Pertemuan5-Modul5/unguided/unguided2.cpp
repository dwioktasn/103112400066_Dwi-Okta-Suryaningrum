#include <iostream>
using namespace std;

struct Node {
    int data;  // angka yang dibawa orang itu
    Node* next; // pointer ke node berikutnya
};

void printList(Node* head) {
    cout << "Linked List yang dibuat: ";
    Node* t = head;
    while (t) {
        cout << t->data;
        if (t->next) cout << " -> ";
        t = t->next;
    }
    cout << " -> NULL\n";
}

// fungsi untuk pencarian linear
Node* linearSearch(Node* head, int key) { //node* ini pointer (kembalian) //fs linear search
    Node* curr = head; // current ini pointer yang nunjuk ke node
    int iter = 1;
    cout << "\nProses Pencarian:\n";
    while (curr) {
        cout << "Memeriksa node " << iter << ": " << curr->data;
        if (curr->data == key) {
            cout << " (SAMA) - DITEMUKAN!\n";
            return curr;
        }
        cout << " (tidak sama)\n";
        curr = curr->next;
        iter++;
    }
    cout << "Tidak ada node lagi yang tersisa\n";
    return nullptr;
}

void append(Node*& head, int value) { //parameter head adalah rederensi ke pointer head //value data yang mau dimasukin
    Node* n = new Node{value, nullptr}; //newnode adalah pointer yang menunjuk ke node baru yang akan dibuat. //value == null karena node baru berada di paling akhir
    if (!head) { //jika head null, head diisi node baru
        head = n;
        return;
    }
    Node* temp = head; // mulai dari head
    while (temp->next)
        temp = temp->next; //pindah ke node berikutnya sampai ketemu node terakhir
    temp->next = n; //node terakhir dihubungkan ke node baru
}

int main() {
    cout << "LINEAR SEARCH PADA LINKED LIST\n";

    Node* head = nullptr; //inisialisasi head list mzsih kosong
    append(head, 10);  //menambah node ke list
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);

    printList(head);

    int key = 30;
    cout << "Mencari nilai: " << key << endl;
    Node* result = linearSearch(head, key);

    if (result) {
        cout << "\nHasil: Nilai " << key << " DITEMUKAN pada linked list!\n";
        cout << "Alamat node: " << result << endl;
        cout << "Data node: " << result->data << endl;
        cout << "Node berikutnya: " << (result->next ? to_string(result->next->data) : "NULL") << endl;
    } else {
        cout << "\nHasil: Nilai " << key << " TIDAK DITEMUKAN dalam linked list!\n";
    }

    key = 25;
    cout << "Mencari nilai: " << key << endl;
    result = linearSearch(head, key);

    if (result) {
        cout << "\nHasil: Nilai " << key << " DITEMUKAN pada linked list!\n";
        cout << "Alamat node: " << result << endl;
        cout << "Data node: " << result->data << endl;
        cout << "Node berikutnya: " << (result->next ? to_string(result->next->data) : "NULL") << endl;
    } else {
        cout << "\nHasil: Nilai " << key << " TIDAK DITEMUKAN dalam linked list!\n";
    }

    return 0;
}
