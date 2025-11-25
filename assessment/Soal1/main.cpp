#include <iostream>
#include <string>
#include "Soal1.h"
using namespace std;

int main() {
    Node* head = NULL;
    int menu;
    string nama;

    do {
        cout << "Menu: 1 insert, 2 delete, 3 view, 4 hitung genap, 0 exit\n";
        cin >> menu;
        cin.ignore(); 

        if (menu == 1) {
            cout << "Masukkan nama: ";
            getline(cin, nama);
            insertLast(head, nama);
        } 
        else if (menu == 2) {
            cout << "Masukkan nama untuk delete: ";
            getline(cin, nama);
            deleteName(head, nama);
        }
        else if (menu == 3) {
            view(head);
        }
        else if (menu == 4) {
            cout << "Jumlah nama dengan huruf genap: " 
                 << hitungGenap(head) << endl;
        }

    } while (menu != 0);

    return 0;
}