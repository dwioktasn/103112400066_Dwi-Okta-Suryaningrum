#include "StackMahasiswa.h"
using namespace std;

bool isEmpty(const StackMahasiswa &StackMHS) {
    return StackMHS.top == Nil;
}

bool isFull(const StackMahasiswa &StackMHS) {
    return StackMHS.top == MaxEl - 1;
}

void createStack(StackMahasiswa &StackMHS) {
    StackMHS.top = Nil;
}

// sekarang push terima parameter Mahasiswa
void push(StackMahasiswa &StackMHS, const Mahasiswa &mhs) {
    if (!isFull(StackMHS)) {
        StackMHS.top++;
        StackMHS.info[StackMHS.top] = mhs;
    } else {
        cout << "Stack Penuh!" << endl;
    }
}

void pop(StackMahasiswa &StackMHS) {
    if (!isEmpty(StackMHS)) {
        StackMHS.top--;
    } else {
        cout << "Stack Kosong!" << endl;
    }
}

void update(StackMahasiswa &StackMHS, int posisi) {
    // posisi pakai indeks array (0 = paling bawah)
    if (posisi >= 0 && posisi <= StackMHS.top) {
        cout << "Masukkan data mahasiswa baru untuk posisi " << posisi << ":\n";
        cout << "Nama        : "; cin >> StackMHS.info[posisi].nama;
        cout << "NIM         : "; cin >> StackMHS.info[posisi].NIM;
        cout << "Nilai Tugas : "; cin >> StackMHS.info[posisi].NilaiTugas;
        cout << "Nilai UTS   : "; cin >> StackMHS.info[posisi].NilaiUTS;
        cout << "Nilai UAS   : "; cin >> StackMHS.info[posisi].NilaiUAS;
    } else {
        cout << "Posisi tidak valid!" << endl;
    }
}

void view(const StackMahasiswa &StackMHS) {
    if (isEmpty(StackMHS)) {
        cout << "Stack Kosong" << endl;
    } else {
        cout << endl;
        for (int i = StackMHS.top; i >= 0; i--) {
            cout << "Nama: " << StackMHS.info[i].nama
                 << ", NIM: " << StackMHS.info[i].NIM
                 << ", Tugas: " << StackMHS.info[i].NilaiTugas
                 << ", UTS: " << StackMHS.info[i].NilaiUTS
                 << ", UAS: " << StackMHS.info[i].NilaiUAS
                 << endl;
        }
    }
}

void searchNilaiAkhir(const StackMahasiswa &StackMHS,
                      float nilaiMin, float nilaiMax) {
    if (isEmpty(StackMHS)) {
        cout << "Stack Kosong" << endl;
    } else {
        cout << "\nMahasiswa dengan Nilai Akhir antara "
             << nilaiMin << " dan " << nilaiMax << ":\n";

        for (int i = StackMHS.top; i >= 0; i--) {
            float nilaiAkhir =
                0.3f * StackMHS.info[i].NilaiTugas +
                0.35f * StackMHS.info[i].NilaiUTS +
                0.35f * StackMHS.info[i].NilaiUAS;

            if (nilaiAkhir >= nilaiMin && nilaiAkhir <= nilaiMax) {
                cout << "Nama: " << StackMHS.info[i].nama
                     << ", NIM: " << StackMHS.info[i].NIM
                     << ", Nilai Akhir: " << nilaiAkhir
                     << endl;
            }
        }
    }
}