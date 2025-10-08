#include <iostream>
#include "pelajaran.h"
using namespace std;

pelajaran create_pelajaran(std::string namapel, std::string kodepel) {
    pelajaran p; 
    p.namaMapel = namapel; 
    p.kodeMapel = kodepel;
    return p; 
}

void tampil_pelajaran(pelajaran pel) {
    cout << "nama pelajaran : " << pel.namaMapel << endl;
    cout << "nilai : " << pel.kodeMapel << endl;
}