#include <iostream>
using namespace std;

//satuan
string satuan(int x){
    if (x == 0) {
        return "nol";
    } else if (x == 1) {
        return "satu";
    } else if (x == 2) {
        return "dua";
    } else if (x == 3) {
        return "tiga";
    } else if (x == 4) {
        return "empat";
    } else if (x == 5) {
        return "lima";
    } else if (x == 6) {
        return "enam";
    } else if (x == 7) {
        return "tujuh";
    } else if (x == 8) {
        return "delapan";
    } else if (x == 9) {
        return "sembilan";
    } else {
        return "";
    }
}

//belasan
string belasan(int x){
    if (x > 10 && x < 20) {
        return "belas";
    } else {
        return "";
    }
}

//puluhan
string puluhan(int x){
    if (x >= 20 && x < 100) {
        return "puluh";
    } else {
        return "";
    }
}

int main(){
    int angka;
    string hasil;

    cout << "Masukkan angka (1-99): ";
    cin >> angka;   
    if (angka < 0 || angka > 100) {
        cout << "Angka di luar jangkauan!" << endl;
        return 0;
    } else if (angka >= 0 && angka < 10) {
        if (angka == 0){
            hasil = "nol";
        } else {
            hasil = satuan(angka);
        }
    } else if (angka == 10){
        hasil = "sepuluh";
    } else if (angka == 11){
        hasil = "sebelas";
    } else if (angka >= 12 && angka < 20){
        hasil = satuan(angka % 10) + " " + belasan(angka);
    } else if (angka >= 20 && angka < 100){
        hasil = satuan(angka / 10) + " " + puluhan(angka) + " " + satuan(angka % 10);
    } else if (angka == 100){
        hasil = "seratus";
    }

    cout << angka << " : " << hasil << endl;
}