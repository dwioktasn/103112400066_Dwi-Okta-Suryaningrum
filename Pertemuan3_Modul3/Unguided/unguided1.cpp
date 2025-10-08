#include <iostream>
using namespace std;

struct mahasiswa {
    string nama;
    char nim[10];
    float uts, uas, tugas, nilaiAkhir;
};

void inputMhs(mahasiswa &m){
    cout << "Masukkan NIM: ";
    cin >> m.nim;
    cout << "Masukkan nama: ";
    cin >> m.nama;
    cout << "Masukkan nilai UTS: ";
    cin >> m.uts;
    cout << "Masukkan nilai UAS: ";
    cin >> m.uas;
    cout << "Masukkan nilai Tugas: ";
    cin >> m.tugas;
}

float nilaiAkhir(mahasiswa m){
    return(float)(0.3*m.uts) + (0.4*m.uas) * (0.3*m.tugas);
}

int main(){
    mahasiswa mhs[10];
    int n;

    cout << "Masukkan jumlah mahasiswa: ";
    cin >> n;

    if(n > 10){
        cout << "Jumlah mahasiswa melebihi batas! Otomatis diatur ke 10." << endl;
        n = 10;
    }

    for(int i=0; i<n; i++){
        cout << "Masukkan data mahasiswa ke-" << i+1 << endl;
        inputMhs(mhs[i]);
        mhs[i].nilaiAkhir = nilaiAkhir(mhs[i]);
    }

    cout << "Data Mahasiswa:" << endl;
    for(int i=0; i<n; i++){
        cout << "NIM: " << mhs[i].nim << ", Nama: " << mhs[i].nama << ", Nilai Akhir: " << mhs[i].nilaiAkhir << endl;
    }

    system("read -p 'Press Enter to continue...' var");

    return 0;
}

