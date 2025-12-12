#include <iostream>
#include "MultiLL.h"
using namespace std;

int main() {
    listParent LP;
    createListParent(LP);

    // =========================
    // INSERT PARENT
    // =========================
    NodeParent P1 = allocNodeParent("G001", "Aves");
    NodeParent P2 = allocNodeParent("G002", "Mamalia");
    NodeParent P3 = allocNodeParent("G003", "Pisces");
    NodeParent P4 = allocNodeParent("G004", "Amfibi");
    NodeParent P5 = allocNodeParent("G005", "Reptil");

    insertLastParent(LP, P1);
    insertLastParent(LP, P2);
    insertLastParent(LP, P3);
    insertLastParent(LP, P4);
    insertLastParent(LP, P5);

    // =========================
    // INSERT CHILD untuk G001 (Aves)
    // =========================
    insertLastChild(P1->L_Child, allocNodeChild("AV001", "Cendrawasih", "Hutan", true, 0.3f));
    insertLastChild(P1->L_Child, allocNodeChild("AV002", "Bebek", "Air", true, 2.0f));

    // =========================
    // INSERT CHILD untuk G002 (Mamalia)
    // urutan ini bikin M003 posisinya ke-2 (sesuai ekspektasi output)
    // =========================
    insertLastChild(P2->L_Child, allocNodeChild("M001", "Harimau", "Hutan", true, 200.0f));
    insertLastChild(P2->L_Child, allocNodeChild("M003", "Gorila", "Hutan", false, 160.0f));
    insertLastChild(P2->L_Child, allocNodeChild("M002", "Kucing", "Darat", true, 4.0f));

    // =========================
    // INSERT CHILD untuk G004 (Amfibi)
    // =========================
    insertLastChild(P4->L_Child, allocNodeChild("AM001", "Kodok", "Sawah", false, 0.2f));

    // =========================
    // PRINT (sesuai instruksi modul setelah INSERT)
    // =========================
    printMLLStructure(LP);

    // =========================
    // SEARCHING: cari hewan dengan EKOR = FALSE
    // (sesuai instruksi tugas & ekspektasi output)
    // =========================
    searchHewanByEkor(LP, false);

    return 0;
}
