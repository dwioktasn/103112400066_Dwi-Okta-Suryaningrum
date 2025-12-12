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
    NodeChild C11 = allocNodeChild("AV001", "Cendrawasih", "Hutan", true, 0.3f);
    NodeChild C12 = allocNodeChild("AV002", "Bebek", "Air", true, 2.0f);

    insertLastChild(P1->L_Child, C11);
    insertLastChild(P1->L_Child, C12);

    // =========================
    // INSERT CHILD untuk G002 (Mamalia)
    // =========================
    NodeChild C21 = allocNodeChild("M001", "Harimau", "Hutan", true, 200.0f);
    NodeChild C22 = allocNodeChild("M003", "Gorila", "Hutan", false, 160.0f);
    NodeChild C23 = allocNodeChild("M002", "Kucing", "Darat", true, 4.0f);

    insertLastChild(P2->L_Child, C21);
    insertLastChild(P2->L_Child, C22);
    insertLastChild(P2->L_Child, C23);

    // =========================
    // INSERT CHILD untuk G004 (Amfibi)
    // =========================
    NodeChild C41 = allocNodeChild("AM001", "Kodok", "Sawah", false, 0.2f);
    insertLastChild(P4->L_Child, C41);

    // =========================
    // PRINT SESUAI PERINTAH MODUL
    // =========================
    printMLLStructure(LP);

    return 0;
}
