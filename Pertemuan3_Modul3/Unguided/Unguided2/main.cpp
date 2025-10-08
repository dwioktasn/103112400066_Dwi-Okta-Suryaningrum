#include <iostream>
#include "pelajaran.h"
#include <cstdlib>

using namespace std;

int main(){
    string namapel = "Struktur Data";
    string kodepel = "STD";

    pelajaran pel = create_pelajaran(namapel, kodepel);
    tampil_pelajaran(pel);

    system("read -p 'Press Enter to continue...' var");

    return 0;
}