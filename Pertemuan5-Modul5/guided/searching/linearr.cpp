#include <iostream>
using namespace std;

// DEFINISI NODE
struct Node{ 
    int data;
    Node* next; // pointer ke node berikutnya
};

// fungsi untuk pencarian linear
Node* linearSearch(Node* head, int key) { //node* ini pointer (kembalian) //fs linear search
    Node* current = head; // current ini pointer yang nunjuk ke node
    while(current != nullptr){ // melakukan pengecekan apakah current tidak bernilai null
        if(current->data == key) return current; //jika ketemu data
        current = current->next; //pindah ke node berikutnya
    }
    return nullptr; // tidak ditemukan
};

void append(Node*& head, int value){ //parameter head adalah rederensi ke pointer head //value data yang mau dimasukin
    Node* newNode = new Node{value,nullptr}; //newnode adalah pointer yang menunjuk ke node baru yang akan dibuat. //value == null karena node baru berada di paling akhir
    if(!head)head = newNode; //jika head null, head diisi node baru
    else{
        Node*temp = head; // mulai dari head
        while (temp->next) temp = temp->next; //pindah ke node berikutnya sampai ketemu node terakhir
        temp->next = newNode; //node terakhir dihubungkan ke node baru
    }
}

int main(){
    Node*head = nullptr; //inisialisasi head list mzsih kosong
    append(head, 10); append(head, 20); append(head, 30); //menambah node ke list

    Node* result = linearSearch(head, 20); //result ini pointer untk mencari data 20
    cout << (result ? "Found" : "Not Found") << endl; // condition ? value_if_true : valie_if_false
    return 0;

}