#ifndef MAHASISWA_H
#define MAHASISWA_H

//definisi tipe
struct mahasiswa {
    char nim[10];
    int nilai1, nilai2;
};

//deklarasi primitid
void inputMhs(mahasiswa &m);
float rata2(mahasiswa m);

#endif