#include "mll.h"
#include <iostream>

using namespace std;

int main() {
    // createListParent()
    ListParent MLL;
    createListParent(MLL);

    // Alokasi dan Insert (G001 - G004)
    NodeParent *g4 = alokasiNodeParent("G004", "Romance");
    insertFirstParent(MLL, g4);
    NodeParent *g3 = alokasiNodeParent("G003", "Horror");
    insertFirstParent(MLL, g3);
    NodeParent *g2 = alokasiNodeParent("G002", "Comedy");
    insertFirstParent(MLL, g2);
    NodeParent *g1 = alokasiNodeParent("G001", "Action");
    insertFirstParent(MLL, g1);

    // Insert Child Data
    insertLastChild(g1->childs, alokasiNodeChild("FA001", "The Raid", 101, 2011, 7.6));
    insertLastChild(g2->childs, alokasiNodeChild("FC001", "Agak Laen", 119, 2024, 8.0));
    insertLastChild(g2->childs, alokasiNodeChild("FC002", "My Stupid Boss", 108, 2016, 6.8));
    insertLastChild(g3->childs, alokasiNodeChild("FH001", "Pengabdi Setan", 107, 2017, 8.4));
    insertLastChild(g4->childs, alokasiNodeChild("FR001", "Habibie & Ainun", 118, 2012, 7.6));
    insertLastChild(g4->childs, alokasiNodeChild("FR002", "Dilan 1990", 110, 2018, 6.6));

    // printStrukturMLL() awal
    cout << "[Print Struktur MLL]" << endl;
    printStrukturMLL(MLL);

    // searchFilmByRatingRange() 8.0 - 8.5
    cout << "\n[Search Rating" << endl;
    searchFilmByRatingRange(MLL, 8.0, 8.5);

    // deleteAfterParent() node G002 (prec adalah G001)
    cout << "\n[Menghapus Node G002 (Comedy)]" << endl;
    NodeParent *deletedNode;
    deleteAfterParent(MLL, g1, deletedNode);
    if (deletedNode != nullptr) {
        dealokasiNodeParent(deletedNode);
    }

    // printStrukturMLL() akhir
    cout << "\n[Print Struktur Setelah G002 Dihapus]" << endl;
    printStrukturMLL(MLL);

    return 0;
}