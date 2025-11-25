#include <iostream>
#include "Soal2.h"
using namespace std;

int main() {
    linkedlist List;
    createList(List);

    int menu, nilai;

    do {
        cout << "Menu: 1 insert (end), 2 delete (last), 3 view (depan), 4 reverse & view (depan), 0 exit\n";
        cin >> menu;

        if (menu == 1) {
            cout << "Masukkan nilai: ";
            cin >> nilai;
            insertLast(List, nilai);
        }
        else if (menu == 2) {
            deleteNilai(List, nilai);
        }
        else if (menu == 3) {
            view(List);
        }
        else if (menu == 4) {
            reserveList(List);
            cout << "List setelah di-reserve " ;
            view(List);
        }

    } while (menu != 0);

    return 0;
}
