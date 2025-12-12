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
    // (M003 harus posisi ke-2)
    // =========================
    insertLastChild(P2->L_Child, allocNodeChild("M001", "Harimau", "Hutan", true, 200.0f));
    insertLastChild(P2->L_Child, allocNodeChild("M003", "Gorila", "Hutan", false, 160.0f));
    insertLastChild(P2->L_Child, allocNodeChild("M002", "Kucing", "Darat", true, 4.0f));

    // =========================
    // INSERT CHILD untuk G004 (Amfibi)
    // =========================
    insertLastChild(P4->L_Child, allocNodeChild("AM001", "Kodok", "Sawah", false, 0.2f));

    // =========================
    // PRINT 1 (setelah insert)
    // =========================
    printMLLStructure(LP);

    // =========================
    // SEARCHING: ekor FALSE
    // =========================
    searchHewanByEkor(LP, false);

    // =========================
    // DELETE: hapus node parent G004 (Amfibi)
    // =========================
    NodeParent prev = NULL;
    NodeParent curr = LP.first;

    while (curr != NULL && curr->isidata.idGolongan != "G004") {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) {
        cout << "Node parent G004 tidak ditemukan.\n";
    } else {
        if (prev == NULL) {
            // berarti G004 ada di first
            deleteFirstParent(LP);
        } else {
            // hapus node setelah prev (yaitu curr = G004)
            deleteAfterParent(LP, prev);
        }
    }

    // =========================
    // PRINT 2 (setelah delete G004)
    // =========================
    printMLLStructure(LP);

    return 0;
}
