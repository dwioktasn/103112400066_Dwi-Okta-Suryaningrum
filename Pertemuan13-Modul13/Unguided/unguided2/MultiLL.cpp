#include "MultiLL.h"

// =====================
// CEK KOSONG
// =====================
bool isEmptyParent(listParent LParent) {
    return (LParent.first == NULL && LParent.last == NULL);
}

bool isEmptyChild(listChild LChild) {
    return (LChild.first == NULL && LChild.last == NULL);
}

// =====================
// CREATE LIST
// =====================
void createListParent(listParent &LParent) {
    LParent.first = NULL;
    LParent.last  = NULL;
}

void createListChild(listChild &LChild) {
    LChild.first = NULL;
    LChild.last  = NULL;
}

// =====================
// ALOKASI NODE
// =====================
NodeParent allocNodeParent(string idGol, string namaGol) {
    NodeParent P = new nodeParent;
    P->isidata.idGolongan   = idGol;
    P->isidata.namaGolongan = namaGol;

    P->next = NULL;
    P->prev = NULL;

    // IMPORTANT: list child harus diinisialisasi
    P->L_Child.first = NULL;
    P->L_Child.last  = NULL;

    return P;
}

NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat,
                         bool tail, float weight) {
    NodeChild C = new nodeChild;
    C->isidata.idHewan   = idHwn;
    C->isidata.namaHewan = namaHwn;
    C->isidata.habitat   = habitat;
    C->isidata.ekor      = tail;
    C->isidata.bobot     = weight;

    C->next = NULL;
    C->prev = NULL;

    return C;
}

// =====================
// DEALOKASI NODE
// =====================
void deallocNodeParent(NodeParent &NParent) {
    delete NParent;
    NParent = NULL;
}

void deallocNodeChild(NodeChild &NChild) {
    delete NChild;
    NChild = NULL;
}

// =====================
// INSERT PARENT (DLL)
// =====================
void insertFirstParent(listParent &LParent, NodeParent newNParent) {
    if (newNParent == NULL) return;

    if (isEmptyParent(LParent)) {
        LParent.first = newNParent;
        LParent.last  = newNParent;
    } else {
        newNParent->next = LParent.first;
        newNParent->prev = NULL;
        LParent.first->prev = newNParent;
        LParent.first = newNParent;
    }
}

void insertLastParent(listParent &LParent, NodeParent newNParent) {
    if (newNParent == NULL) return;

    if (isEmptyParent(LParent)) {
        LParent.first = newNParent;
        LParent.last  = newNParent;
    } else {
        newNParent->prev = LParent.last;
        newNParent->next = NULL;
        LParent.last->next = newNParent;
        LParent.last = newNParent;
    }
}

// =====================
// DELETE PARENT (DLL)
// =====================
void deleteFirstParent(listParent &LParent) {
    if (isEmptyParent(LParent)) return;

    NodeParent P = LParent.first;

    // hapus semua child dulu biar aman (hindari memory leak)
    deleteListChild(P->L_Child);

    if (LParent.first == LParent.last) {
        LParent.first = NULL;
        LParent.last  = NULL;
    } else {
        LParent.first = P->next;
        LParent.first->prev = NULL;
        P->next = NULL;
    }

    P->prev = NULL;
    deallocNodeParent(P);
}

void deleteAfterParent(listParent &LParent, NodeParent NPrev) {
    if (isEmptyParent(LParent)) return;
    if (NPrev == NULL) return;
    if (NPrev->next == NULL) return; // tidak ada setelahnya

    NodeParent P = NPrev->next;

    // hapus semua child dulu
    deleteListChild(P->L_Child);

    if (P == LParent.last) {
        LParent.last = NPrev;
        NPrev->next = NULL;
    } else {
        NPrev->next = P->next;
        P->next->prev = NPrev;
        P->next = NULL;
    }

    P->prev = NULL;
    deallocNodeParent(P);
}

// =====================
// INSERT CHILD (DLL)
// =====================
void insertFirstChild(listChild &LChild, NodeChild newNChild) {
    if (newNChild == NULL) return;

    if (isEmptyChild(LChild)) {
        LChild.first = newNChild;
        LChild.last  = newNChild;
    } else {
        newNChild->next = LChild.first;
        newNChild->prev = NULL;
        LChild.first->prev = newNChild;
        LChild.first = newNChild;
    }
}

void insertLastChild(listChild &LChild, NodeChild newNChild) {
    if (newNChild == NULL) return;

    if (isEmptyChild(LChild)) {
        LChild.first = newNChild;
        LChild.last  = newNChild;
    } else {
        newNChild->prev = LChild.last;
        newNChild->next = NULL;
        LChild.last->next = newNChild;
        LChild.last = newNChild;
    }
}

// =====================
// DELETE CHILD (DLL)
// =====================
void deleteFirstChild(listChild &LChild) {
    if (isEmptyChild(LChild)) return;

    NodeChild C = LChild.first;

    if (LChild.first == LChild.last) {
        LChild.first = NULL;
        LChild.last  = NULL;
    } else {
        LChild.first = C->next;
        LChild.first->prev = NULL;
        C->next = NULL;
    }

    C->prev = NULL;
    deallocNodeChild(C);
}

void deleteAfterChild(listChild &LChild, NodeChild NPrev) {
    if (isEmptyChild(LChild)) return;
    if (NPrev == NULL) return;
    if (NPrev->next == NULL) return;

    NodeChild C = NPrev->next;

    if (C == LChild.last) {
        LChild.last = NPrev;
        NPrev->next = NULL;
    } else {
        NPrev->next = C->next;
        C->next->prev = NPrev;
        C->next = NULL;
    }

    C->prev = NULL;
    deallocNodeChild(C);
}

// =====================
// DELETE SEMUA CHILD
// =====================
void deleteListChild(listChild &LChild) {
    while (!isEmptyChild(LChild)) {
        deleteFirstChild(LChild);
    }
}

// =====================
// PRINT MLL STRUCTURE
// =====================
void printMLLStructure(listParent &LParent) {
    if (isEmptyParent(LParent)) {
        cout << "(List Parent kosong)\n";
        return;
    }

    NodeParent P = LParent.first;
    int iParent = 1;

    while (P != NULL) {
        cout << "=== Parent " << iParent << " ===\n";
        cout << "ID Golongan : " << P->isidata.idGolongan << "\n";
        cout << "Nama Golongan : " << P->isidata.namaGolongan << "\n";

        if (isEmptyChild(P->L_Child)) {
            cout << "(tidak ada child)\n";
        } else {
            NodeChild C = P->L_Child.first;
            int iChild = 1;
            while (C != NULL) {
                cout << " - Child " << iChild << " :\n";
                cout << "   ID Hewan : " << C->isidata.idHewan << "\n";
                cout << "   Nama Hewan : " << C->isidata.namaHewan << "\n";
                cout << "   Habitat : " << C->isidata.habitat << "\n";
                cout << "   Ekor : " << (C->isidata.ekor ? "1" : "0") << "\n";
                cout << "   Bobot : " << C->isidata.bobot << "\n";

                C = C->next;
                iChild++;
            }
        }

        cout << "------------------------------\n";
        P = P->next;
        iParent++;
    }
}

void searchHewanByEkor(listParent &LParent, bool tail) {
    if (isEmptyParent(LParent)) {
        cout << "(List Parent kosong)\n";
        return;
    }

    NodeParent P = LParent.first;
    int indexParent = 1;
    bool foundAny = false;

    while (P != NULL) {
        NodeChild C = P->L_Child.first;
        int indexChild = 1;

        while (C != NULL) {
            if (C->isidata.ekor == tail) {
                cout << "Data ditemukan pada list anak dari node parent "
                     << P->isidata.namaGolongan
                     << " pada posisi ke-" << indexChild << "!\n";

                cout << "--- Data Child ---\n";
                cout << "ID Child : " << C->isidata.idHewan << "\n";
                cout << "Posisi dalam list anak : posisi ke-" << indexChild << "\n";
                cout << "Nama Hewan : " << C->isidata.namaHewan << "\n";
                cout << "Habitat : " << C->isidata.habitat << "\n";
                cout << "Ekor : " << (C->isidata.ekor ? 1 : 0) << "\n";
                cout << "Bobot : " << C->isidata.bobot << "\n";

                cout << "------------------------------\n";

                cout << "--- Data Parent ---\n";
                cout << "ID Parent : " << P->isidata.idGolongan << "\n";
                cout << "Posisi dalam list induk : posisi ke-" << indexParent << "\n";
                cout << "Nama golongan : " << P->isidata.namaGolongan << "\n";

                cout << "------------------------------\n";

                foundAny = true;
            }

            C = C->next;
            indexChild++;
        }

        P = P->next;
        indexParent++;
    }

    if (!foundAny) {
        cout << "Tidak ada hewan dengan kriteria ekor yang dicari.\n";
    }
}