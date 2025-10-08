#ifndef PELAJARAN_H
#define PELAJARAN_H
#include <string> 

using namespace std;

//definisi tipe
struct pelajaran {
   string namaMapel;
   string kodeMapel;
};

pelajaran create_pelajaran(string namapel, string kodepel);
void tampil_pelajaran(pelajaran pel);

#endif

// g++ main.cpp pelajaran.cpp -o pelajaran
