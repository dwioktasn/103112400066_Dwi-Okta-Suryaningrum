#include <iostream>
using namespace std;

void tampilkanHasil(int arr[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}   

void jumlahMatriks(int arrA[3][3], int arrB[3][3], int arrC[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            arrC[i][j] = arrA[i][j] + arrB[i][j];
        }
    }
    cout << "Hasil penjumlahan: " << endl;
    tampilkanHasil(arrC);
}

void kurangMatriks(int arrA[3][3], int arrB[3][3], int arrC[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            arrC[i][j] = arrA[i][j] - arrB[i][j];
        }
    }
    cout << "Hasil pengurangan: " << endl;
    tampilkanHasil(arrC);
}

void kaliMatriks(int arrA[3][3], int arrB[3][3], int arrD[3][3]){
    for(int i = 0; i < 3; i++){                      //perulangan baris
        for(int j = 0; j < 3; j++){                  //perulangan kolom 
            for (int k =0; k < 3; k++){              //perulangan perkalian  
                arrD[i][j] += arrA[i][k] * arrB[k][j];
            }
        }
    }
    cout << "Hasil perkalian: " << endl;
    tampilkanHasil(arrD);
}
int main(){
    int arrA[3][3]={
        {7, 12, 22},
        {31, 6, 41},
        {15, 19, 36}
    };
    int arrB[3][3]={
        {11, 34, 7},
        {3, 25, 41},
        {5, 18, 33}
    };
    int arrC[3][3]={0};
    int arrD[3][3]={0};

    int pilihan;
    cout << " --- Menu Program Matriks --- " << endl;
    cout << "1. Penjumlahan Matriks" << endl;
    cout << "2. Pengurangan Matriks" << endl;
    cout << "3. Perkalian Matriks" << endl;
    cout << "4. Keluar " << endl;

    cout << "Masukkan pilihan : ";
    cin >> pilihan;
    switch (pilihan)
    {
    case 1:
        jumlahMatriks(arrA, arrB, arrC);
        break;
    case 2:
        kurangMatriks(arrA, arrB, arrC);
        break;
    case 3:
        kaliMatriks(arrA, arrB, arrD);
        break;
    default:
        break;
    }
}