#include <iostream>
using namespace std;

struct mahasiswa {
    char nim[10];
    float nilai1, nilai2;
};

void inputMhs(mahasiswa &m){
    cout << "Masukkan NIM: ";
    cin >> m.nim;
    cout << "Masukkan nilai 1: ";
    cin >> m.nilai1;
    cout << "Masukkan nilai 2: ";
    cin >> m.nilai2;
}

float rata2(mahasiswa m){
    return(float)(m.nilai1 + m.nilai2) / 2;
}

int main(){
    mahasiswa mhs;

    inputMhs(mhs);

    cout << "Data-rata nilai adalah :" << rata2(mhs) << endl;

    system("read -p 'Press Enter to continue...' var");

    return 0;
}