#include "mll.h"

void createListParent(ListParent &L) {
    L.first = nullptr;
    L.last = nullptr;
}

void createListChild(ListChild &L) {
    L.first = nullptr;
    L.last = nullptr;
}

NodeParent* alokasiNodeParent(string id, string nama) {
    NodeParent *P = new NodeParent;
    P->IDGenre = id;
    P->namaGenre = nama;
    P->next = nullptr;
    P->prev = nullptr;
    createListChild(P->childs);
    return P;
}

NodeChild* alokasiNodeChild(string id, string judul, int durasi, int tahun, float rating) {
    NodeChild *P = new NodeChild;
    P->IDFilm = id;
    P->judulFilm = judul;
    P->durasiFilm = durasi;
    P->tahunTayang = tahun;
    P->ratingFilm = rating;
    P->next = nullptr;
    P->prev = nullptr;
    return P;
}

void dealokasiNodeParent(NodeParent *&P) { delete P; P = nullptr; }
void dealokasiNodeChild(NodeChild *&P) { delete P; P = nullptr; }

void insertFirstParent(ListParent &L, NodeParent *P) {
    if (L.first == nullptr) {
        L.first = L.last = P;
    } else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}

void insertLastChild(ListChild &L, NodeChild *P) {
    if (L.first == nullptr) {
        L.first = L.last = P;
    } else {
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    }
}

void hapusListChild(ListChild &L) {
    NodeChild *P = L.first;
    while (P != nullptr) {
        NodeChild *temp = P;
        P = P->next;
        dealokasiNodeChild(temp);
    }
    L.first = L.last = nullptr;
}

void deleteAfterParent(ListParent &L, NodeParent *prec, NodeParent *&P) {
    if (prec == nullptr || prec->next == nullptr) {
        P = nullptr;
        return;
    }
    P = prec->next;
    hapusListChild(P->childs);
    if (P == L.last) {
        L.last = prec;
        prec->next = nullptr;
    } else {
        prec->next = P->next;
        P->next->prev = prec;
    }
    P->next = P->prev = nullptr;
}

void searchFilmByRatingRange(ListParent L, float minRate, float maxRate) {
    NodeParent *P = L.first;
    int posP = 1;
    while (P != nullptr) {
        NodeChild *C = P->childs.first;
        int posC = 1;
        while (C != nullptr) {
            if (C->ratingFilm >= minRate && C->ratingFilm <= maxRate) {
                cout << "Data Film ditemukan pada list child dari node parent " << P->namaGenre << " pada posisi ke-" << posC << "!" << endl;
                cout << "--- Data Film (Child) ---" << endl;
                cout << "Judul Film : " << C->judulFilm << endl;
                cout << "Posisi dalam list child : posisi ke-" << posC << endl;
                cout << "ID Film : " << C->IDFilm << endl;
                cout << "Durasi Film : " << C->durasiFilm << " menit" << endl;
                cout << "Tahun Tayang : " << C->tahunTayang << endl;
                cout << "Rating Film : " << C->ratingFilm << endl;
                cout << "-------------------------" << endl;
                cout << "--- Data Genre (Parent) ---" << endl;
                cout << "ID Genre : " << P->IDGenre << endl;
                cout << "Posisi dalam list parent : posisi ke-" << posP << endl;
                cout << "Nama Genre : " << P->namaGenre << endl;
                cout << "========================================" << endl;
            }
            C = C->next;
            posC++;
        }
        P = P->next;
        posP++;
    }
}

void printStrukturMLL(ListParent L) {
    NodeParent *P = L.first;
    int countP = 1;
    while (P != nullptr) {
        cout << "=== Parent " << countP << " ===" << endl;
        cout << "ID Genre : " << P->IDGenre << endl;
        cout << "Nama Genre : " << P->namaGenre << endl;
        NodeChild *C = P->childs.first;
        int countC = 1;
        while (C != nullptr) {
            cout << " - Child " << countC << " :" << endl;
            cout << "   ID Film : " << C->IDFilm << endl;
            cout << "   Judul Film : " << C->judulFilm << endl;
            cout << "   Durasi Film : " << C->durasiFilm << " menit" << endl;
            cout << "   Tahun Tayang : " << C->tahunTayang << endl;
            cout << "   Rating Film : " << C->ratingFilm << endl;
            C = C->next;
            countC++;
        }
        cout << "--------------------------" << endl;
        P = P->next;
        countP++;
    }
}