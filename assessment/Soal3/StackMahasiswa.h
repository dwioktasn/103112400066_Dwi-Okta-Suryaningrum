#ifndef STACKMAHASISWA_H
#define STACKMAHASISWA_H

#include <iostream>
using namespace std;

#define MaxEl 6
#define Nil -1

struct Mahasiswa {
    string nama;
    string NIM;
    float NilaiTugas;
    float NilaiUTS;
    float NilaiUAS;
}; 

struct StackMahasiswa {
    Mahasiswa info[MaxEl]; // array untuk menyimpan elemen stack
    int top;               // indeks top stack
};

// PROTOTYPE FUNGSI
bool isEmpty(const StackMahasiswa &StackMHS);
bool isFull(const StackMahasiswa &StackMHS);
void createStack(StackMahasiswa &StackMHS);
void push(StackMahasiswa &StackMHS, const Mahasiswa &mhs);
void pop(StackMahasiswa &StackMHS);
void update(StackMahasiswa &StackMHS, int posisi);
void view(const StackMahasiswa &StackMHS);
void searchNilaiAkhir(const StackMahasiswa &StackMHS, float nilaiMin, float nilaiMax);

#endif
