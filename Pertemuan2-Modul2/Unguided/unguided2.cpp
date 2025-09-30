#include <iostream>
using namespace std;

void ubahNilai(int *ptrPanjang, int *ptrLebar, int &refLuas, int &refKeliling){
    refLuas = (*ptrPanjang) * (*ptrLebar); //menghitung luas
    refKeliling = 2 * ((*ptrPanjang) + (*ptrLebar)); //menghitung keliling
}
int main(){
    int panjang = 10;
    int lebar = 5;
    int luas = 0;
    int keliling = 0;

    cout << "--- Nilai Awal : ---" << endl;
    cout << "Panjang : " << panjang << endl;
    cout << "Lebar : " << lebar << endl;
    cout << endl;

    ubahNilai(&panjang, &lebar, luas, keliling);
    cout << "--- Hasil Perhitungan ---" << endl;
    cout << "Luas Persegi Panjang : " << luas << endl;
    cout << "Keliling Persegi Panjang : " << keliling << endl;
    cout << endl;

    cout << "--- Nilai Setelah Perhitungan ---" << endl;
    cout << "Panjang baru : ";
    cin >> panjang;
    cout << "Lebar baru : ";
    cin >> lebar;
    ubahNilai(&panjang, &lebar, luas, keliling);
    cout << "Luas Baru: " << luas << endl;
    cout << "Keliling Baru: " << keliling << endl;
}